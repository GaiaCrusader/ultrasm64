#ifndef RENDERING_GRAPH_NODE_H
#define RENDERING_GRAPH_NODE_H

#include <PR/ultratypes.h>

#include "engine/graph_node.h"

#define THROWMATSTACK 24
#define MATRIX_NULL 250

typedef struct RenderNode {
    Gfx *dl;
    Gfx *material;
    Mtx *mtx;
    s32 aaMode;
    struct RenderNode *next;
    struct RenderNode *prev;
} RenderNode;

typedef struct RenderList {
    RenderNode *entryHead;
    struct RenderList *next;
} RenderList;

extern struct GraphNodeRoot *gCurGraphNodeRoot;
extern struct GraphNodeMasterList *gCurGraphNodeMasterList;
extern struct GraphNodePerspective *gCurGraphNodeCamFrustum;
extern struct GraphNodeCamera *gCurGraphNodeCamera;
extern struct GraphNodeObject *gCurGraphNodeObject;
extern struct GraphNodeHeldObject *gCurGraphNodeHeldObject;
#define gCurGraphNodeObjectNode ((struct Object *)gCurGraphNodeObject)
extern u16 gAreaUpdateCounter;
extern Mat4 gThrowMatStack[2][THROWMATSTACK];
extern u16 gThrowMatIndex;
extern u8 gThrowMatSwap;
extern Mat4 gCameraTransform;
extern u8 gScreenMode;
extern u8 gFrameCap;
extern u8 gDedither;
extern s8 gAntiAliasing;
extern u8 gCameraSnap;

// after processing an object, the type is reset to this
#define ANIM_TYPE_NONE                  0

// Not all parts have full animation: to save space, some animations only
// have xz, y, or no translation at all. All animations have rotations though
#define ANIM_TYPE_TRANSLATION           1
#define ANIM_TYPE_VERTICAL_TRANSLATION  2
#define ANIM_TYPE_LATERAL_TRANSLATION   3
#define ANIM_TYPE_NO_TRANSLATION        4

// Every animation includes rotation, after processing any of the above
// translation types the type is set to this
#define ANIM_TYPE_ROTATION              5

void geo_process_node_and_siblings(struct GraphNode *firstNode);
void geo_process_root(struct GraphNodeRoot *node, Vp *b, Vp *c, s32 clearColor);
void update_graph_node_camera(struct GraphNodeCamera *gc);

#endif // RENDERING_GRAPH_NODE_H
