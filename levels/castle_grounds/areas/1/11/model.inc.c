// TODO: what is this? 0700C4C0-0700C4C8 [8,8]

// 0x0700C4C8 - 0x0700C4E0

// 0x0700C4E0 - 0x0700C4F8

// 0x0700C500 - 0x0700C530
static const Vtx castle_grounds_seg7_vertex_0700C500[] = {
    {{{     0,      0,     75}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   287,      0,      0}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,    -74}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
};

// 0x0700C530 - 0x0700C570
static const Vtx castle_grounds_seg7_vertex_0700C530[] = {
    {{{     0,      0,    150}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   287,      0,     75}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   287,      0,    -74}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,   -149}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700C570 - 0x0700C5B0
static const Vtx castle_grounds_seg7_vertex_0700C570[] = {
    {{{     0,      0,    240}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   345,      0,    150}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   345,      0,   -149}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,   -239}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700C5B0 - 0x0700C5F0
static const Vtx castle_grounds_seg7_vertex_0700C5B0[] = {
    {{{     0,      0,    360}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   460,      0,    240}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   460,      0,   -239}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,   -359}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700C5F0 - 0x0700C640
static const Vtx castle_grounds_seg7_vertex_0700C5F0[] = {
    {{{   460,      0,   -359}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,   -479}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,      0}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,    480}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   460,      0,    360}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x0700C640 - 0x0700C670
static const Vtx castle_grounds_seg7_vertex_0700C640[] = {
    {{{   460,      0,    360}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{   460,      0,   -359}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
    {{{     0,      0,      0}, 0, {     0,      0}, {0x00, 0x7f, 0x00, 0x00}}},
};

// 0x0700C670 - 0x0700C6A8
const Gfx castle_grounds_seg7_dl_0700C670[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0xff0000ff),
    gsSPLightColor(LIGHT_2, 0x660000ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C500, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

// 0x0700C6A8 - 0x0700C6E8
const Gfx castle_grounds_seg7_dl_0700C6A8[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0xff0000ff),
    gsSPLightColor(LIGHT_2, 0x660000ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C530, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

// 0x0700C6E8 - 0x0700C728
const Gfx castle_grounds_seg7_dl_0700C6E8[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0xff0000ff),
    gsSPLightColor(LIGHT_2, 0x660000ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C570, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

// 0x0700C728 - 0x0700C768
const Gfx castle_grounds_seg7_dl_0700C728[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0xff0000ff),
    gsSPLightColor(LIGHT_2, 0x660000ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C5B0, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};

// 0x0700C768 - 0x0700C7C8
const Gfx castle_grounds_seg7_dl_0700C768[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x666666ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C5F0, 5, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  2,  3,  4, 0x0),
    gsSPLightColor(LIGHT_1, 0xff0000ff),
    gsSPLightColor(LIGHT_2, 0x660000ff),
    gsSPVertex(castle_grounds_seg7_vertex_0700C640, 3, 0),
    gsSP1Triangle( 0,  1,  2, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
