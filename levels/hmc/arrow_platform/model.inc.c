// 0x07022B48 - 0x07022B60

// 0x07022B60 - 0x07022C60
static const Vtx hmc_seg7_vertex_07022B60[] = {
    {{{   307,     51,    307}, 0, {  3004,    -12}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -306,      0,    307}, 0, {    -2,    990}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   307,      0,    307}, 0, {  3004,    990}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -306,     51,    307}, 0, {    -2,    -12}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -306,      0,   -306}, 0, {    -2,    990}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   307,     51,   -306}, 0, {  3004,    -12}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   307,      0,   -306}, 0, {  3004,    990}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -306,     51,   -306}, 0, {    -2,    -12}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   307,      0,   -306}, 0, {  3004,    990}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   307,     51,   -306}, 0, {  3004,    -12}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   307,     51,    307}, 0, {    -2,    -12}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{   307,      0,    307}, 0, {    -2,    990}, {0x7f, 0x00, 0x00, 0xff}}},
    {{{  -306,      0,    307}, 0, {    -2,    990}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -306,     51,    307}, 0, {    -2,    -12}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -306,     51,   -306}, 0, {  3004,    -12}, {0x81, 0x00, 0x00, 0xff}}},
    {{{  -306,      0,   -306}, 0, {  3004,    990}, {0x81, 0x00, 0x00, 0xff}}},
};

// 0x07022C60 - 0x07022CE0
static const Vtx hmc_seg7_vertex_07022C60[] = {
    {{{   307,      0,    307}, 0, {  3004,  -2046}, {0x00, 0x81, 0x00, 0xff}}},
    {{{  -306,      0,   -306}, 0, {    -2,    960}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   307,      0,   -306}, 0, {  3004,    960}, {0x00, 0x81, 0x00, 0xff}}},
    {{{  -306,      0,    307}, 0, {    -2,  -2046}, {0x00, 0x81, 0x00, 0xff}}},
    {{{   307,     51,   -306}, 0, {  1982,  -1024}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -306,     51,   -306}, 0, { -1022,  -1024}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{  -306,     51,    307}, 0, { -1022,   1980}, {0x00, 0x7f, 0x00, 0xff}}},
    {{{   307,     51,    307}, 0, {  1982,   1980}, {0x00, 0x7f, 0x00, 0xff}}},
};

// 0x07022CE0 - 0x07022D58
static const Gfx hmc_seg7_dl_07022CE0[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hmc_seg7_texture_07004000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLightColor(LIGHT_1, 0xffffffff),
    gsSPLightColor(LIGHT_2, 0x797979ff),
    gsSPVertex(hmc_seg7_vertex_07022B60, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  7,  5, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  8, 10, 11, 0x0),
    gsSP2Triangles(12, 13, 14, 0x0, 12, 14, 15, 0x0),
    gsSPEndDisplayList(),
};

// 0x07022D58 - 0x07022DA0
static const Gfx hmc_seg7_dl_07022D58[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hmc_seg7_texture_07003000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(hmc_seg7_vertex_07022C60, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  6,  7, 0x0),
    gsSPEndDisplayList(),
};

// 0x07022DA0 - 0x07022E78
const Gfx hmc_seg7_dl_07022DA0[] = {
    gsDPPipeSync(),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(hmc_seg7_dl_07022CE0),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(hmc_seg7_dl_07022D58),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_PASS2),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
