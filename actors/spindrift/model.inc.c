// Spindrift



// 0x05000030

// 0x05000048


// 0x05000078

// 0x05000090


// 0x050000C0
static const Vtx spindrift_seg5_vertex_050000C0[] = {
    {{{    34,     40,     30}, 0, {     0,      0}, {0x7b, 0x17, 0x11, 0x00}}},
    {{{    34,    -16,     46}, 0, {     0,      0}, {0x7b, 0xf7, 0x1c, 0x00}}},
    {{{    46,      0,      0}, 0, {     0,      0}, {0x7f, 0x00, 0x00, 0x00}}},
    {{{    34,    -50,      0}, 0, {     0,      0}, {0x7b, 0xe3, 0x00, 0xff}}},
    {{{    34,    -16,    -46}, 0, {     0,      0}, {0x7b, 0xf7, 0xe3, 0xff}}},
    {{{    34,     40,    -28}, 0, {     0,      0}, {0x7b, 0x18, 0xee, 0xff}}},
};

// 0x05000120
static const Vtx spindrift_seg5_vertex_05000120[] = {
    {{{     6,      0,      0}, 0, {     0,      0}, {0x81, 0x00, 0x00, 0x00}}},
    {{{    34,    -16,    -46}, 0, {     0,      0}, {0x92, 0xee, 0xc4, 0x00}}},
    {{{    34,    -50,      0}, 0, {     0,      0}, {0x92, 0xc2, 0x00, 0x00}}},
    {{{    34,    -16,     46}, 0, {     0,      0}, {0x92, 0xec, 0x3b, 0xff}}},
    {{{    34,     40,    -28}, 0, {     0,      0}, {0x92, 0x32, 0xdb, 0xff}}},
    {{{    34,     40,     30}, 0, {     0,      0}, {0x92, 0x31, 0x25, 0xff}}},
};

// 0x05000180
static const Vtx spindrift_seg5_vertex_05000180[] = {
    {{{    70,     50,      0}, 0, {     0,      0}, {0xcb, 0x73, 0x00, 0x00}}},
    {{{    24,    -12,     56}, 0, {     0,      0}, {0xa9, 0x22, 0x54, 0x00}}},
    {{{   128,     -2,     94}, 0, {     0,      0}, {0xda, 0x45, 0x63, 0x00}}},
    {{{     0,     -5,      0}, 0, {     0,      0}, {0x8e, 0x37, 0x00, 0xff}}},
    {{{    24,    -12,    -56}, 0, {     0,      0}, {0xa8, 0x22, 0xac, 0xff}}},
    {{{     0,    -57,      0}, 0, {     0,      0}, {0x87, 0xdd, 0x00, 0xff}}},
    {{{    55,   -113,     57}, 0, {     0,      0}, {0xa5, 0xce, 0x48, 0xff}}},
    {{{   128,     -2,    -94}, 0, {     0,      0}, {0xda, 0x45, 0x9d, 0xff}}},
    {{{    55,   -113,    -57}, 0, {     0,      0}, {0xa5, 0xce, 0xb8, 0xff}}},
};

// 0x05000210
static const Vtx spindrift_seg5_vertex_05000210[] = {
    {{{    55,   -113,    -57}, 0, {     0,      0}, {0xa5, 0xce, 0xb8, 0x00}}},
    {{{    55,   -113,     57}, 0, {     0,      0}, {0xa5, 0xce, 0x48, 0x00}}},
    {{{     0,    -57,      0}, 0, {     0,      0}, {0x87, 0xdd, 0x00, 0x00}}},
    {{{   128,     -2,    -94}, 0, {     0,      0}, {0xda, 0x45, 0x9d, 0xff}}},
    {{{    24,    -12,    -56}, 0, {     0,      0}, {0xa8, 0x22, 0xac, 0xff}}},
    {{{   128,     -2,     94}, 0, {     0,      0}, {0xda, 0x45, 0x63, 0xff}}},
    {{{    24,    -12,     56}, 0, {     0,      0}, {0xa9, 0x22, 0x54, 0xff}}},
    {{{   138,     66,      0}, 0, {     0,      0}, {0xe3, 0x7b, 0x00, 0xff}}},
    {{{    70,     50,      0}, 0, {     0,      0}, {0xcb, 0x73, 0x00, 0xff}}},
};

// 0x050002A0 - 0x05000328
const Gfx spindrift_seg5_dl_050002A0[] = {
    gsSPLightColor(LIGHT_1, 0xddff01ff),
    gsSPLightColor(LIGHT_2, 0x373f00ff),
    gsSPVertex(spindrift_seg5_vertex_050000C0, 6, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  4,  2, 0x0),
    gsSP2Triangles( 1,  3,  2, 0x0,  4,  5,  2, 0x0),
    gsSP1Triangle( 5,  0,  2, 0x0),
    gsSPLightColor(LIGHT_1, 0x49b200ff),
    gsSPLightColor(LIGHT_2, 0x122c00ff),
    gsSPVertex(spindrift_seg5_vertex_05000120, 6, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 1,  0,  4, 0x0,  4,  0,  5, 0x0),
    gsSP1Triangle( 5,  0,  3, 0x0),
    gsSPEndDisplayList(),
};

// 0x05000328 - 0x050003D8
const Gfx spindrift_seg5_dl_05000328[] = {
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPLightColor(LIGHT_1, 0x3f00ff),
    gsSPLightColor(LIGHT_2, 0xf00ff),
    gsSPVertex(spindrift_seg5_vertex_05000180, 9, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  0,  3, 0x0),
    gsSP2Triangles( 0,  4,  3, 0x0,  1,  5,  6, 0x0),
    gsSP2Triangles( 7,  4,  0, 0x0,  5,  4,  8, 0x0),
    gsSP2Triangles( 5,  1,  3, 0x0,  4,  5,  3, 0x0),
    gsSPLightColor(LIGHT_1, 0xffe200ff),
    gsSPLightColor(LIGHT_2, 0x3f3800ff),
    gsSPVertex(spindrift_seg5_vertex_05000210, 9, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  3,  0,  4, 0x0),
    gsSP2Triangles( 1,  5,  6, 0x0,  5,  7,  8, 0x0),
    gsSP1Triangle( 8,  7,  3, 0x0),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPEndDisplayList(),
};
