#include <PR/ultratypes.h>

#ifdef VERSION_EU
#include "prevent_bss_reordering.h"
#endif

#include "debug_utils.h"
#include "gd_main.h"
#include "gd_math.h"
#include "gd_types.h"
#include "joints.h"
#include "macros.h"
#include "objects.h"
#include "particles.h"
#include "renderer.h"
#include "skin.h"
#include "skin_movement.h"

// bss
struct ObjNet *gGdSkinNet; // @ 801BAAF0

static s32 D_801BAAF4;
static s32 sNetCount; // @ 801BAAF8

/* 2406E0 -> 240894 */
void compute_net_bounding_box(struct ObjNet *net) {
    reset_bounding_box();
    if (net->unk1D0 != NULL) {
        apply_to_obj_types_in_group(OBJ_TYPE_ALL, (applyproc_t) add_obj_pos_to_bounding_box, net->unk1D0);
    }
    if (net->unk1C8 != NULL) {
        apply_to_obj_types_in_group(OBJ_TYPE_ALL, (applyproc_t) add_obj_pos_to_bounding_box, net->unk1C8);
    }
    gSomeBoundingBox.minX *= net->scale.x;
    gSomeBoundingBox.maxX *= net->scale.x;
    gSomeBoundingBox.minY *= net->scale.y;
    gSomeBoundingBox.maxY *= net->scale.y;
    gSomeBoundingBox.minZ *= net->scale.z;
    gSomeBoundingBox.maxZ *= net->scale.z;

    net->boundingBox.minX = gSomeBoundingBox.minX;
    net->boundingBox.minY = gSomeBoundingBox.minY;
    net->boundingBox.minZ = gSomeBoundingBox.minZ;
    net->boundingBox.maxX = gSomeBoundingBox.maxX;
    net->boundingBox.maxY = gSomeBoundingBox.maxY;
    net->boundingBox.maxZ = gSomeBoundingBox.maxZ;
}

/* 240894 -> 240A64; orig name: func_801920C4 */
void reset_net(struct ObjNet *net) {
    struct ObjGroup *grp;

    printf("reset_net %d\n", net->id);

    net->worldPos.x = net->initPos.x;
    net->worldPos.y = net->initPos.y;
    net->worldPos.z = net->initPos.z;
    net->velocity.x = net->velocity.y = net->velocity.z = 0.0f;
    net->torque.x = net->torque.y = net->torque.z = 0.0f;

    compute_net_bounding_box(net);

    gGdSkinNet = net;
    D_801BAAF4 = 0;
    gd_set_identity_mat4(&net->mat168);
    gd_set_identity_mat4(&net->matE8);
    gd_rot_mat_about_vec(&net->matE8, &net->unk68); // set rot mtx to initial rotation?
    gd_add_vec3f_to_mat4f_offset(&net->matE8, &net->worldPos); // set to initial position?
    gd_copy_mat4f(&net->matE8, &net->mat128);

    if ((grp = net->unk1C8) != NULL) {
        apply_to_obj_types_in_group(OBJ_TYPE_JOINTS, (applyproc_t) reset_joint, grp);
        apply_to_obj_types_in_group(OBJ_TYPE_JOINTS, (applyproc_t) func_80191220, grp);
        apply_to_obj_types_in_group(OBJ_TYPE_BONES, (applyproc_t) func_8018FB58, grp);
        apply_to_obj_types_in_group(OBJ_TYPE_BONES, (applyproc_t) func_8018FA68, grp);
    }
}

/* 240A64 -> 240ACC */
void func_80192294(struct ObjNet *net) {
    if (net->attachedToObj == NULL) {
        transform_child_objects_recursive(&net->header, NULL);
    }
}

/* 240ACC -> 240B84 */
void func_801922FC(struct ObjNet *net) {
    struct ObjGroup *group; // 24

    gGdSkinNet = net;
    // TODO: netype constants?
    if (net->netType == 4) {
        if (net->shapePtr != NULL) {
            D_801B9E38 = &net->mat128;
            scale_verts(net->shapePtr->vtxGroup);
        }
        if ((group = net->unk1C8) != NULL) {
            apply_to_obj_types_in_group(OBJ_TYPE_JOINTS, (applyproc_t) reset_joint_weights, group);
        }
    }
}

/* 240B84 -> 240CF8 */
struct ObjNet *make_net(UNUSED s32 a0, struct ObjShape *shapedata, struct ObjGroup *a2,
                        struct ObjGroup *a3, struct ObjGroup *a4) {
    struct ObjNet *net;

    net = (struct ObjNet *) make_object(OBJ_TYPE_NETS);
    gd_set_identity_mat4(&net->mat128);
    net->initPos.x = net->initPos.y = net->initPos.z = 0.0f;
    net->id = ++sNetCount;
    net->scale.x = net->scale.y = net->scale.z = 1.0f;
    net->shapePtr = shapedata;
    net->unk1C8 = a2;
    net->unk1CC = a3;
    net->unk1D0 = a4;
    net->netType = 0;
    net->ctrlType = 0;
    net->unk21C = NULL;
    net->unk3C = 1;
    net->colourNum = 0;
    net->skinGrp = NULL;
    reset_net(net);

    return net;
}

/* 24142C -> 24149C; orig name: func_80192C5C */
void move_bonesnet(struct ObjNet *net) {
    struct ObjGroup *sp24;

    gd_set_identity_mat4(&D_801B9DC8);
    if ((sp24 = net->unk1C8) != NULL) {
        apply_to_obj_types_in_group(OBJ_TYPE_JOINTS, (applyproc_t) func_801913C0, sp24);
    }
}

/* 241768 -> 241AB4; orig name: func_80192F98 */
void convert_gd_verts_to_Vn(struct ObjGroup *grp) {
    Vtx *vn;       // 28
    s32 nx, ny, nz; // 24, 25, 26
    register struct VtxLink *vtxlink; // a1
    register s16 *vnPos;              // a2
    register s32 x;                   // a3
    register s32 y;                   // t0
    register s32 z;                   // t1
    register struct ObjVertex *vtx;   // t2
    register struct ListNode *link;      // t3
    struct GdObj *obj;                // sp4

    for (link = grp->firstMember; link != NULL; link = link->next) {
        obj = link->obj;
        vtx = (struct ObjVertex *) obj;
        x = vtx->pos.x;
        y = vtx->pos.y;
        z = vtx->pos.z;

        nx = (vtx->normal.x * 255.0f);
        ny = (vtx->normal.y * 255.0f);
        nz = (vtx->normal.z * 255.0f);

        for (vtxlink = vtx->gbiVerts; vtxlink != NULL; vtxlink = vtxlink->prev) {
            vnPos = vtxlink->data->n.ob;
            vn = vtxlink->data;
            *vnPos++ = x;
            *vnPos++ = y;
            *vnPos++ = z;
            vn->n.n[0] = nx;
            vn->n.n[1] = ny;
            vn->n.n[2] = nz;
        }
    }
}

/* 241AB4 -> 241BCC; orig name: func_801932E4 */
void convert_gd_verts_to_Vtx(struct ObjGroup *grp) {
    register struct VtxLink *vtxlink; // a1
    register s16 *vtxcoords;          // a2
    register s32 x;                   // a3
    register s32 y;                   // t0
    register s32 z;                   // t1
    register struct ObjVertex *vtx;   // t2
    register struct ListNode *link;      // t3
    struct GdObj *obj;                // sp4

    for (link = grp->firstMember; link != NULL; link = link->next) {
        obj = link->obj;
        vtx = (struct ObjVertex *) obj;
        x = vtx->pos.x;
        y = vtx->pos.y;
        z = vtx->pos.z;

        for (vtxlink = vtx->gbiVerts; vtxlink != NULL; vtxlink = vtxlink->prev) {
            vtxcoords = vtxlink->data->v.ob;
            vtxcoords[0] = x;
            vtxcoords[1] = y;
            vtxcoords[2] = z;
        }
    }
}

/* 241BCC -> 241CA0; orig name: Proc801933FC */
void convert_net_verts(struct ObjNet *net) {
    if (net->shapePtr != NULL) {
        if (net->shapePtr->unk30) {
            convert_gd_verts_to_Vn(net->shapePtr->vtxGroup);
        }
    }

    switch (net->netType) {
        case 2:
            if (net->shapePtr != NULL) {
                convert_gd_verts_to_Vtx(net->shapePtr->scaledVtxGroup);
            }
            break;
    }
}

/* 241CA0 -> 241D6C */
static void move_joints_in_net(struct ObjNet *net) {
    struct ObjGroup *grp;        // 2c
    register struct ListNode *link; // s0
    struct GdObj *obj;           // 24

    if ((grp = net->unk1C8) != NULL) {
        for (link = grp->firstMember; link != NULL; link = link->next) {
            obj = link->obj;
            switch (obj->type) {
                case OBJ_TYPE_JOINTS:
                    if (((struct ObjJoint *) obj)->updateFunc != NULL) {
                        (*((struct ObjJoint *) obj)->updateFunc)((struct ObjJoint *) obj);
                    }
                    break;
                default:;
            }
        }
    }
}

/* 241D6C -> 241E94; orig name: func_8019359C */
void move_net(struct ObjNet *net) {
    gGdSkinNet = net;

    switch (net->netType) {
        case 4:
            move_bonesnet(net);
            break;
        case 2:
            move_skin(net);
            break;
        case 3:
            move_joints_in_net(net);
            break;
    }
}

/* 241E94 -> 241F0C; orig name: func_801936C4 */
void move_nets(struct ObjGroup *group) {
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) func_80192294, group);
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) move_net, group);
}

/* 241F0C -> 242018 */
void func_8019373C(struct ObjNet *net) {
    register struct ListNode *link;
    struct ObjVertex *vtx;

    switch (net->netType) {
        case 2:
            if (net->shapePtr != NULL) {
                net->shapePtr->scaledVtxGroup = make_group(0);
                for (link = net->shapePtr->vtxGroup->firstMember; link != NULL; link = link->next) {
                    vtx = (struct ObjVertex *) link->obj;
                    if (vtx->scaleFactor != 1.0f) {
                        addto_group(net->shapePtr->scaledVtxGroup, &vtx->header);
                    }
                }
            }
            break;
    }
}

/* 242018 -> 24208C */
void func_80193848(struct ObjGroup *group) {
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) reset_net, group);
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) func_80192294, group);
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) func_801922FC, group);
    apply_to_obj_types_in_group(OBJ_TYPE_NETS, (applyproc_t) func_8019373C, group);
}

/* 2422E0 -> 2422F8; orig name: func_80193B10 */
void reset_net_count(void) {
    sNetCount = 0;
}
