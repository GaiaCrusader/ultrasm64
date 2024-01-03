#include <PR/ultratypes.h>

#include "sm64.h"
#include "game/ingame_menu.h"
#include "graph_node.h"
#include "behavior_script.h"
#include "behavior_data.h"
#include "game/memory.h"
#include "game/object_helpers.h"
#include "game/macro_special_objects.h"
#include "surface_collision.h"
#include "game/mario.h"
#include "game/object_list_processor.h"
#include "surface_load.h"

/**
 * Partitions for course and object surfaces. The arrays represent
 * the 16x16 cells that each level is split into.
 */
SpatialPartitionCell gStaticSurfacePartition[NUM_CELLS][NUM_CELLS];
SpatialPartitionCell gDynamicSurfacePartition[NUM_CELLS][NUM_CELLS];
struct CellCoords {
    u8 z;
    u8 x;
    u8 partition;
};
struct CellCoords sCellsUsed[NUM_CELLS];
u16 sNumCellsUsed;
u8 sClearAllCells;

/**
 * Pools of data that can contain either surface nodes or surfaces.
 * The static surface pool is resized to be exactly the amount of memory needed for the level geometry.
 * The dynamic surface pool is set at a fixed length and cleared every frame.
 */
void *gCurrStaticSurfacePool;
void *gDynamicSurfacePool;
void *gDynamicSurfaceNodePool;

/**
 * The end of the data currently allocated to the surface pools.
 */
void *gCurrStaticSurfacePoolEnd;
void *gDynamicSurfacePoolEnd;
void *gDynamicSurfaceNodePoolEnd;

/**
 * The amount of data currently allocated to static surfaces.
 */
u32 gTotalStaticSurfaceData;

/**
 * Allocate the part of the surface node pool to contain a surface node.
 */
struct SurfaceNode *alloc_surface_node(u32 dynamic) {
    struct SurfaceNode **poolEnd = (struct SurfaceNode **)(dynamic ? &gDynamicSurfaceNodePoolEnd : &gCurrStaticSurfacePoolEnd);

    struct SurfaceNode *node = *poolEnd;
    (*poolEnd)++;
    gSurfaceNodesAllocated++;

    node->next = NULL;

    return node;
}

/**
 * Allocate the part of the surface pool to contain a surface and
 * initialize the surface.
 */
struct Surface *alloc_surface(u32 dynamic) {
    struct Surface **poolEnd = (struct Surface **)(dynamic ? &gDynamicSurfacePoolEnd : &gCurrStaticSurfacePoolEnd);
    
    struct Surface *surface = *poolEnd;
    (*poolEnd)++;
    gSurfacesAllocated++;

    surface->type = SURFACE_DEFAULT;
    surface->force = 0;
    surface->flags = 0;
    surface->room = 0;
    surface->object = NULL;

    return surface;
}

/**
 * Iterates through the entire partition, clearing the surfaces.
 */
void clear_spatial_partition(SpatialPartitionCell *cells) {
    for (u32 i = 0; i < NUM_CELLS * NUM_CELLS; i++) {
        (*cells)[SPATIAL_PARTITION_FLOORS].next = NULL;
        (*cells)[SPATIAL_PARTITION_CEILS].next = NULL;
        (*cells)[SPATIAL_PARTITION_WALLS].next = NULL;

        cells++;
    }
}

/**
 * Clears the static (level) surface partitions for new use.
 */
void clear_static_surfaces(void) {
    gTotalStaticSurfaceData = 0;
    clear_spatial_partition(&gStaticSurfacePartition[0][0]);
}

/**
 * Add a surface to the correct cell list of surfaces.
 * @param dynamic Determines whether the surface is static or dynamic
 * @param cellX The X position of the cell in which the surface resides
 * @param cellZ The Z position of the cell in which the surface resides
 * @param surface The surface to add
 */
void add_surface_to_cell(s16 dynamic, s16 cellX, s16 cellZ, struct Surface *surface) {
    struct SurfaceNode *list;
    s16 sortDir;
    s16 listIndex;

    
    f32 normal[4];
    get_surface_normal(normal, surface);

    if (normal[1] > 0.01f) {
        listIndex = SPATIAL_PARTITION_FLOORS;
        sortDir = 1; // highest to lowest, then insertion order
    } else if (normal[1] < -0.01f) {
        listIndex = SPATIAL_PARTITION_CEILS;
        sortDir = -1; // lowest to highest, then insertion order
    } else {
        listIndex = SPATIAL_PARTITION_WALLS;
        sortDir = 0; // insertion order

        if (normal[0] < -0.707f || normal[0] > 0.707f) {
            surface->flags |= SURFACE_FLAG_X_PROJECTION;
        }
    }

    //! (Surface Cucking) Surfaces are sorted by the height of their first
    //  vertex. Since vertices aren't ordered by height, this causes many
    //  lower triangles to be sorted higher. This worsens surface cucking since
    //  many functions only use the first triangle in surface order that fits,
    //  missing higher surfaces.
    //  upperY would be a better sort method.

    struct SurfaceNode *newNode = alloc_surface_node(dynamic);
    newNode->surface = surface;

    if (dynamic) {
        list = &gDynamicSurfacePartition[cellZ][cellX][listIndex];
        if (sNumCellsUsed >= sizeof(sCellsUsed) / sizeof(struct CellCoords)) {
            sClearAllCells = TRUE;
        } else {
            if (list->next == NULL) {
                sCellsUsed[sNumCellsUsed].x = cellX;
                sCellsUsed[sNumCellsUsed].z = cellZ;
                sCellsUsed[sNumCellsUsed].partition = listIndex;
                sNumCellsUsed++;
            }
        }
    } else {
        list = &gStaticSurfacePartition[cellZ][cellX][listIndex];
    }

    // Vanilla relies on surface sorting to not be completely broken.
    // Walls I can safely ignore though.
    if (listIndex != SPATIAL_PARTITION_WALLS) {
        s32 surfacePriority = surface->vertex1[1] * sortDir;
        while (list->next != NULL) {
            s32 priority = list->next->surface->vertex1[1] * sortDir;
            if (surfacePriority > priority) {
                break;
            }
            list = list->next;
        }
    }

    newNode->next = list->next;
    list->next = newNode;
}

/**
 * Returns the lowest of three values.
 */
s32 min_3(s32 a0, s32 a1, s32 a2) {
    if (a1 < a0) {
        a0 = a1;
    }

    if (a2 < a0) {
        a0 = a2;
    }

    return a0;
}

/**
 * Returns the highest of three values.
 */
s32 max_3(s32 a0, s32 a1, s32 a2) {
    if (a1 > a0) {
        a0 = a1;
    }

    if (a2 > a0) {
        a0 = a2;
    }

    return a0;
}

/**
 * Every level is split into 16 * 16 cells of surfaces (to limit computing
 * time). This function determines the lower cell for a given x/z position.
 * @param coord The coordinate to test
 */
s32 lower_cell_index(s32 coord) {
    s32 index;

    // Move from range [-0x2000, 0x2000) to [0, 0x4000)
    coord += LEVEL_BOUNDARY_MAX;
    if (coord < 0) {
        coord = 0;
    }

    // [0, 16)
    index = coord / CELL_SIZE;

    // Include extra cell if close to boundary
    //! Some wall checks are larger than the buffer, meaning wall checks can
    //  miss walls that are near a cell border.
    if (coord % CELL_SIZE < 50) {
        index--;
    }

    if (index < 0) {
        index = 0;
    }

    // Potentially > 15, but since the upper index is <= 15, not exploitable
    return index;
}

/**
 * Every level is split into 16 * 16 cells of surfaces (to limit computing
 * time). This function determines the upper cell for a given x/z position.
 * @param coord The coordinate to test
 */
s32 upper_cell_index(s32 coord) {
    s32 index;

    // Move from range [-0x2000, 0x2000) to [0, 0x4000)
    coord += LEVEL_BOUNDARY_MAX;
    if (coord < 0) {
        coord = 0;
    }

    // [0, 16)
    index = coord / CELL_SIZE;

    // Include extra cell if close to boundary
    //! Some wall checks are larger than the buffer, meaning wall checks can
    //  miss walls that are near a cell border.
    if (coord % CELL_SIZE > CELL_SIZE - 50) {
        index++;
    }

    if (index > NUM_CELLS_INDEX) {
        index = NUM_CELLS_INDEX;
    }

    // Potentially < 0, but since lower index is >= 0, not exploitable
    return index;
}

/**
 * Every level is split into 16x16 cells, this takes a surface, finds
 * the appropriate cells (with a buffer), and adds the surface to those
 * cells.
 * @param surface The surface to check
 * @param dynamic Boolean determining whether the surface is static or dynamic
 */
void add_surface(struct Surface *surface, s32 dynamic) {
    s32 minX, minZ, maxX, maxZ;

    s32 minCellX, minCellZ, maxCellX, maxCellZ;

    s32 cellZ, cellX;

    minX = min_3(surface->vertex1[0], surface->vertex2[0], surface->vertex3[0]);
    minZ = min_3(surface->vertex1[2], surface->vertex2[2], surface->vertex3[2]);
    maxX = max_3(surface->vertex1[0], surface->vertex2[0], surface->vertex3[0]);
    maxZ = max_3(surface->vertex1[2], surface->vertex2[2], surface->vertex3[2]);

    minCellX = lower_cell_index(minX);
    maxCellX = upper_cell_index(maxX);
    minCellZ = lower_cell_index(minZ);
    maxCellZ = upper_cell_index(maxZ);

    for (cellZ = minCellZ; cellZ <= maxCellZ; cellZ++) {
        for (cellX = minCellX; cellX <= maxCellX; cellX++) {
            add_surface_to_cell(dynamic, cellX, cellZ, surface);
        }
    }
}

/**
 * Initializes a Surface struct using the given vertex data
 * @param vertexData The raw data containing vertex positions
 * @param vertexIndices Helper which tells positions in vertexData to start reading vertices
 */
struct Surface *read_surface_data(s16 *vertexData, s16 **vertexIndices, u32 dynamic) {
    struct Surface *surface;
    register s32 x1, y1, z1;
    register s32 x2, y2, z2;
    register s32 x3, y3, z3;
    s32 maxY, minY;
    f32 nx, ny, nz;
    f32 mag;
    s32 offset1, offset2, offset3;

    offset1 = 3 * (*vertexIndices)[0];
    offset2 = 3 * (*vertexIndices)[1];
    offset3 = 3 * (*vertexIndices)[2];

    x1 = *(vertexData + offset1 + 0);
    y1 = *(vertexData + offset1 + 1);
    z1 = *(vertexData + offset1 + 2);

    x2 = *(vertexData + offset2 + 0);
    y2 = *(vertexData + offset2 + 1);
    z2 = *(vertexData + offset2 + 2);

    x3 = *(vertexData + offset3 + 0);
    y3 = *(vertexData + offset3 + 1);
    z3 = *(vertexData + offset3 + 2);

    // (v2 - v1) x (v3 - v2)
    nx = (y2 - y1) * (z3 - z2) - (z2 - z1) * (y3 - y2);
    ny = (z2 - z1) * (x3 - x2) - (x2 - x1) * (z3 - z2);
    nz = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
    mag = (nx * nx + ny * ny + nz * nz);

    // Checking to make sure no DIV/0
    if (mag < 0.0001f) {
        return NULL;
    }

    // Could have used min_3 and max_3 for this...
    minY = y1;
    if (y2 < minY) {
        minY = y2;
    }
    if (y3 < minY) {
        minY = y3;
    }

    maxY = y1;
    if (y2 > maxY) {
        maxY = y2;
    }
    if (y3 > maxY) {
        maxY = y3;
    }

    surface = alloc_surface(dynamic);

    surface->vertex1[0] = x1;
    surface->vertex2[0] = x2;
    surface->vertex3[0] = x3;

    surface->vertex1[1] = y1;
    surface->vertex2[1] = y2;
    surface->vertex3[1] = y3;

    surface->vertex1[2] = z1;
    surface->vertex2[2] = z2;
    surface->vertex3[2] = z3;

    surface->lowerY = minY - 5;
    surface->upperY = maxY + 5;

    return surface;
}

/**
 * Returns whether a surface has exertion/moves Mario
 * based on the surface type.
 */
s32 surface_has_force(s16 surfaceType) {
    s32 hasForce = FALSE;

    switch (surfaceType) {
        case SURFACE_FLOWING_WATER:
        case SURFACE_DEEP_MOVING_QUICKSAND:
        case SURFACE_SHALLOW_MOVING_QUICKSAND:
        case SURFACE_MOVING_QUICKSAND:
        case SURFACE_HORIZONTAL_WIND:
        case SURFACE_INSTANT_MOVING_QUICKSAND:
            hasForce = TRUE;
            break;

        default:
            break;
    }
    return hasForce;
}

/**
 * Returns whether a surface should have the
 * SURFACE_FLAG_NO_CAM_COLLISION flag.
 */
s32 surf_has_no_cam_collision(s16 surfaceType) {
    s32 flags = 0;

    switch (surfaceType) {
        case SURFACE_NO_CAM_COLLISION:
        case SURFACE_NO_CAM_COL_VERY_SLIPPERY:
        case SURFACE_SWITCH:
            flags = SURFACE_FLAG_NO_CAM_COLLISION;
            break;
    }

    return flags;
}

/**
 * Load in the surfaces for a given surface type. This includes setting the flags,
 * exertion, and room.
 */
void load_static_surfaces(s16 **data, s16 *vertexData, s16 surfaceType, s8 **surfaceRooms) {
    s32 numSurfaces;
    struct Surface *surface;
    s8 room = 0;
    s16 hasForce = surface_has_force(surfaceType);
    s16 flags = surf_has_no_cam_collision(surfaceType);

    numSurfaces = *(*data)++;

    for (s32 i = 0; i < numSurfaces; i++) {
        if (*surfaceRooms != NULL) {
            room = *(*surfaceRooms);
            (*surfaceRooms)++;
        }

        surface = read_surface_data(vertexData, data, FALSE);
        if (surface != NULL) {
            surface->room = room;
            surface->type = surfaceType;
            surface->flags = flags;

            if (hasForce) {
                surface->force = *(*data + 3);
            } else {
                surface->force = 0;
            }

            add_surface(surface, FALSE);
        }

        *data += 3;
        if (hasForce) {
            (*data)++;
        }
    }
}

/**
 * Read the data for vertices for reference by triangles.
 */
s16 *read_vertex_data(s16 **data) {
    s32 numVertices = *(*data)++;

    s16 *vertexData = *data;
    *data += 3 * numVertices;

    return vertexData;
}

/**
 * Loads in special environmental regions, such as water, poison gas, and JRB fog.
 */
void load_environmental_regions(s16 **data) {
    s32 i;

    gEnvironmentRegions = *data;
    s32 numRegions = *(*data)++;

    for (i = 0; i < numRegions; i++) {
        *data += 5;
        gEnvironmentLevels[i] = *(*data)++;
    }
}

/**
 * Allocate some of the main pool for surfaces (2300 surf) and for surface nodes (7000 nodes).
 */
void alloc_surface_pools(void) {
    // Single define for memory, and split it into thirds, giving 1 to the poolsize and 2 to the nodesize.
    gDynamicSurfacePool = main_pool_alloc(DYNAMIC_SURFACE_POOL_SIZE * 0.33f, MEMORY_POOL_LEFT);
    gDynamicSurfaceNodePool = main_pool_alloc(DYNAMIC_SURFACE_POOL_SIZE * 0.66f, MEMORY_POOL_LEFT);
    gDynamicSurfaceNodePoolEnd = gDynamicSurfaceNodePool;
    gDynamicSurfacePoolEnd = gDynamicSurfacePool;

    gCCMEnteredSlide = FALSE;
    reset_red_coins_collected();
}

/**
 * Process the level file, loading in vertices, surfaces, some objects, and environmental
 * boxes (water, gas, JRB fog).
 */
void load_area_terrain(s16 index, s16 *data, s8 *surfaceRooms, s16 *macroObjects) {
    s16 terrainLoadType;
    s16 *vertexData = NULL;
    u32 surfacePoolData;

    // Initialize the data for this.
    gEnvironmentRegions = NULL;
    gSurfaceNodesAllocated = 0;
    gSurfacesAllocated = 0;
    sNumCellsUsed = 0;
    sClearAllCells = TRUE;

    clear_static_surfaces();
    // Initialise a new surface pool for this block of static surface data
    gCurrStaticSurfacePool = main_pool_alloc(main_pool_available() - 0x10, MEMORY_POOL_LEFT);
    gCurrStaticSurfacePoolEnd = gCurrStaticSurfacePool;

    // A while loop iterating through each section of the level data. Sections of data
    // are prefixed by a terrain "type." This type is reused for surfaces as the surface
    // type.
    while (TRUE) {
        terrainLoadType = *data;
        data++;

        if (TERRAIN_LOAD_IS_SURFACE_TYPE_LOW(terrainLoadType)) {
            load_static_surfaces(&data, vertexData, terrainLoadType, &surfaceRooms);
        } else if (terrainLoadType == TERRAIN_LOAD_VERTICES) {
            vertexData = read_vertex_data(&data);
        } else if (terrainLoadType == TERRAIN_LOAD_OBJECTS) {
            spawn_special_objects(index, &data);
        } else if (terrainLoadType == TERRAIN_LOAD_ENVIRONMENT) {
            load_environmental_regions(&data);
        } else if (terrainLoadType == TERRAIN_LOAD_CONTINUE) {
            continue;
        } else if (terrainLoadType == TERRAIN_LOAD_END) {
            break;
        } else if (TERRAIN_LOAD_IS_SURFACE_TYPE_HIGH(terrainLoadType)) {
            load_static_surfaces(&data, vertexData, terrainLoadType, &surfaceRooms);
            continue;
        }
    }

    if (macroObjects != NULL && *macroObjects != -1) {
        // If the first macro object presetID is within the range [0, 29].
        // Generally an early spawning method, every object is in BBH (the first level).
        if (0 <= *macroObjects && *macroObjects < 30) {
            spawn_macro_objects_hardcoded(index, macroObjects);
        }
        // A more general version that can spawn more objects.
        else {
            spawn_macro_objects(index, macroObjects);
        }
    }

    surfacePoolData = (uintptr_t)gCurrStaticSurfacePoolEnd - (uintptr_t)gCurrStaticSurfacePool;
    gTotalStaticSurfaceData += surfacePoolData;
    main_pool_realloc(gCurrStaticSurfacePool, surfacePoolData);
    gNumStaticSurfaceNodes = gSurfaceNodesAllocated;
    gNumStaticSurfaces = gSurfacesAllocated;
}

/**
 * If not in time stop, clear the surface partitions.
 */
void clear_dynamic_surfaces(void) {
    if (!(gTimeStopState & TIME_STOP_ACTIVE)) {
        clear_dynamic_surface_references();
        gSurfacesAllocated = gNumStaticSurfaces;
        gSurfaceNodesAllocated = gNumStaticSurfaceNodes;
        gDynamicSurfacePoolEnd = gDynamicSurfacePool;
        gDynamicSurfaceNodePoolEnd = gDynamicSurfaceNodePool;
        if (sClearAllCells) {
            clear_spatial_partition(&gDynamicSurfacePartition[0][0]);
        } else {
            for (u32 i = 0; i < sNumCellsUsed; i++) {
                gDynamicSurfacePartition[sCellsUsed[i].z][sCellsUsed[i].x][sCellsUsed[i].partition].next = NULL;
            }
        }
        sNumCellsUsed = 0;
        sClearAllCells = FALSE;
    }
}

/**
 * Applies an object's transformation to the object's vertices.
 */
void transform_object_vertices(s16 **data, s16 *vertexData) {
    register s16 *vertices;
    register f32 vx, vy, vz;
    register s32 numVertices;

    Mat4 *objectTransform;
    Mat4 m;

    objectTransform = &gCurrentObject->transform;

    numVertices = *(*data);
    (*data)++;

    vertices = *data;

    if (gCurrentObject->header.gfx.throwMatrix == NULL) {
        gCurrentObject->header.gfx.throwMatrix = objectTransform;
        obj_build_transform_from_pos_and_angle(gCurrentObject, O_POS_INDEX, O_FACE_ANGLE_INDEX);
    }

    obj_apply_scale_to_matrix(gCurrentObject, m, *objectTransform);

    // Go through all vertices, rotating and translating them to transform the object.
    while (numVertices--) {
        vx = *(vertices++);
        vy = *(vertices++);
        vz = *(vertices++);

        //! No bounds check on vertex data
        *vertexData++ = (s16)(vx * m[0][0] + vy * m[1][0] + vz * m[2][0] + m[3][0]);
        *vertexData++ = (s16)(vx * m[0][1] + vy * m[1][1] + vz * m[2][1] + m[3][1]);
        *vertexData++ = (s16)(vx * m[0][2] + vy * m[1][2] + vz * m[2][2] + m[3][2]);
    }

    *data = vertices;
}

/**
 * Load in the surfaces for the gCurrentObject. This includes setting the flags, exertion, and room.
 */
void load_object_surfaces(s16 **data, s16 *vertexData, u32 dynamic) {
    s16 hasForce;
    s16 flags;
    s16 room;

    s32 surfaceType = *(*data)++;
    s32 numSurfaces = *(*data)++;


    hasForce = surface_has_force(surfaceType);

    flags = surf_has_no_cam_collision(surfaceType) | (dynamic ? SURFACE_FLAG_DYNAMIC : 0);

    // The DDD warp is initially loaded at the origin and moved to the proper
    // position in paintings.c and doesn't update its room, so set it here.
    if (gCurrentObject->behavior == segmented_to_virtual(bhvDddWarp)) {
        room = 5;
    } else {
        room = 0;
    }

    for (s32 i = 0; i < numSurfaces; i++) {
        struct Surface *surface = read_surface_data(vertexData, data, dynamic);

        if (surface != NULL) {
            surface->object = gCurrentObject;
            surface->type = surfaceType;

            if (hasForce) {
                surface->force = *(*data + 3);
            } else {
                surface->force = 0;
            }

            surface->flags |= flags;
            surface->room = room;
            add_surface(surface, dynamic);
        }

        if (hasForce) {
            *data += 4;
        } else {
            *data += 3;
        }
    }
}


s16 sDynamicVertices[900];

/**
 * Transform an object's vertices, reload them, and render the object.
 */
void load_object_collision_model(void) {;

    s16 *collisionData = gCurrentObject->collisionData;
    f32 marioDist = gCurrentObject->oDistanceToMario;
    f32 tangibleDist = gCurrentObject->oCollisionDistance;

    // If the object collision is supposed to be loaded more than the
    // drawing distance of 4000, extend the drawing range.
    if (gCurrentObject->oCollisionDistance > 4000.0f) {
        gCurrentObject->oDrawingDistance = gCurrentObject->oCollisionDistance;
    }

    // Update if no Time Stop, in range, and in the current room.
    if (!(gTimeStopState & TIME_STOP_ACTIVE) && marioDist < tangibleDist
        && !(gCurrentObject->activeFlags & ACTIVE_FLAG_IN_DIFFERENT_ROOM)) {
        collisionData++;
        transform_object_vertices(&collisionData, sDynamicVertices);

        // TERRAIN_LOAD_CONTINUE acts as an "end" to the terrain data.
        while (*collisionData != TERRAIN_LOAD_CONTINUE) {
            load_object_surfaces(&collisionData, sDynamicVertices, TRUE);
        }
    }

    if (marioDist < gCurrentObject->oDrawingDistance) {
        gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_ACTIVE;
    } else {
        gCurrentObject->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;
    }
}

/**
 * Transform an object's vertices and add them to the static surface pool.
 */
void load_object_static_model(void) {
    s16 *collisionData = gCurrentObject->collisionData;
    u32 surfacePoolData;

    // Initialise a new surface pool for this block of surface data
    gCurrStaticSurfacePool = main_pool_alloc(main_pool_available() - 0x10, MEMORY_POOL_LEFT);
    gCurrStaticSurfacePoolEnd = gCurrStaticSurfacePool;
    gSurfaceNodesAllocated = gNumStaticSurfaceNodes;
    gSurfacesAllocated = gNumStaticSurfaces;

    collisionData++;
    transform_object_vertices(&collisionData, sDynamicVertices);

    // TERRAIN_LOAD_CONTINUE acts as an "end" to the terrain data.
    while (*collisionData != TERRAIN_LOAD_CONTINUE) {
        load_object_surfaces(&collisionData, sDynamicVertices, FALSE);
    }

    surfacePoolData = (uintptr_t)gCurrStaticSurfacePoolEnd - (uintptr_t)gCurrStaticSurfacePool;
    gTotalStaticSurfaceData += surfacePoolData;
    main_pool_realloc(gCurrStaticSurfacePool, surfacePoolData);

    gNumStaticSurfaceNodes = gSurfaceNodesAllocated;
    gNumStaticSurfaces = gSurfacesAllocated;
}