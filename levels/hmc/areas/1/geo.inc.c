// 0x0E0005E8
const GeoLayout hmc_geo_0005E8[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070078B0),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07007B50),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_070080E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070093F0),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000618
const GeoLayout hmc_geo_000618[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700E448),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0700EF00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700F3E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700FA40),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700FEF0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_seg7_dl_07010070),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000658
const GeoLayout hmc_geo_000658[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07013CA8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07013E80),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014300),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014B08),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07014C00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014E48),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0702, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E0006A8
const GeoLayout hmc_geo_0006A8[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070173A8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07017C98),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07018200),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07019248),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07019368),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E0006E0
const GeoLayout hmc_geo_0006E0[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701A080),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701A400),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000700
const GeoLayout hmc_geo_000700[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701E820),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701F1B0),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F690),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F818),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701FD58),
      GEO_ASM(0, geo_movtex_pause_control),
      GEO_ASM(0x0701, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000748
const GeoLayout hmc_geo_000748[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07020FD0),
      GEO_ASM(0, geo_painting_update),
      GEO_ASM(PAINTING_ID(0, 0), geo_painting_draw),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000770
const GeoLayout hmc_geo_000770[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07021760),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07021BA0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070228A0),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000798
const GeoLayout hmc_geo_000798[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070078B0),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07007B50),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_070080E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070093F0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700E448),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0700EF00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700F3E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700FA40),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700FEF0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_seg7_dl_07010070),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E0007F8
const GeoLayout hmc_geo_0007F8[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070078B0),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07007B50),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_070080E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070093F0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070173A8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07017C98),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07018200),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07019248),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07019368),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000850
const GeoLayout hmc_geo_000850[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700E448),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0700EF00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700F3E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700FA40),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700FEF0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_seg7_dl_07010070),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07013CA8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07013E80),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014300),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014B08),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07014C00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014E48),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0702, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E0008D0
const GeoLayout hmc_geo_0008D0[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700E448),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0700EF00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700F3E8),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0700FA40),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0700FEF0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_seg7_dl_07010070),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070173A8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07017C98),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07018200),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07019248),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07019368),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000938
const GeoLayout hmc_geo_000938[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07013CA8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07013E80),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014300),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014B08),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07014C00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014E48),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701A080),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701A400),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0702, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000998
const GeoLayout hmc_geo_000998[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07013CA8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07013E80),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014300),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014B08),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07014C00),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07014E48),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701E820),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701F1B0),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F690),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F818),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701FD58),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0701, geo_movtex_draw_water_regions),
      GEO_ASM(0x0702, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000A18
const GeoLayout hmc_geo_000A18[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070173A8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07017C98),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07018200),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07019248),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07019368),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701E820),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701F1B0),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F690),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F818),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701FD58),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0701, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000A88
const GeoLayout hmc_geo_000A88[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701E820),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701F1B0),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F690),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F818),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701FD58),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07020FD0),
      GEO_ASM(   0, geo_painting_update),
      GEO_ASM(   PAINTING_ID(0, 0), geo_painting_draw),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0701, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000AE8
const GeoLayout hmc_geo_000AE8[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701E820),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701F1B0),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F690),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_0701F818),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701FD58),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07021760),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07021BA0),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070228A0),
      GEO_ASM(   0, geo_movtex_pause_control),
      GEO_ASM(0x0701, geo_movtex_draw_water_regions),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000B48
const GeoLayout hmc_geo_000B48[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_070173A8),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_07017C98),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07018200),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_07019248),
      GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_seg7_dl_07019368),
      GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_seg7_dl_0701A080),
      GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_seg7_dl_0701A400),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

static const GeoLayout ddd_geo_bg_a2[] = {
   GEO_NODE_START(),
      GEO_ZBUFFER(0),
      GEO_OPEN_NODE(),
         GEO_NODE_ORTHO(100),
         GEO_OPEN_NODE(),
            GEO_BACKGROUND_COLOR(0x0001),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x0E000B90
const GeoLayout hmc_geo_000B90[] = {
   GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(2, geo_switch_BG),
      GEO_OPEN_NODE(),
         GEO_BRANCH(1, ddd_geo_bg_a2),
      GEO_CLOSE_NODE(),
      GEO_ZBUFFER(1),
      GEO_OPEN_NODE(),
         GEO_CAMERA_FRUSTUM_WITH_FUNC(45, 100, 12800, geo_camera_fov),
         GEO_OPEN_NODE(),
            GEO_CAMERA(16, 0, 2000, 6000, 0, 0, 0, geo_camera_main),
            GEO_OPEN_NODE(),
               GEO_SWITCH_CASE(18, geo_switch_area),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, hmc_geo_0005E8), // 0x0E0005E8
                  GEO_BRANCH(1, hmc_geo_000618), // 0x0E000618
                  GEO_BRANCH(1, hmc_geo_000658), // 0x0E000658
                  GEO_BRANCH(1, hmc_geo_0006A8), // 0x0E0006A8
                  GEO_BRANCH(1, hmc_geo_0006E0), // 0x0E0006E0
                  GEO_BRANCH(1, hmc_geo_000700), // 0x0E000700
                  GEO_BRANCH(1, hmc_geo_000748), // 0x0E000748
                  GEO_BRANCH(1, hmc_geo_000770), // 0x0E000770
                  GEO_BRANCH(1, hmc_geo_000798), // 0x0E000798
                  GEO_BRANCH(1, hmc_geo_0007F8), // 0x0E0007F8
                  GEO_BRANCH(1, hmc_geo_000850), // 0x0E000850
                  GEO_BRANCH(1, hmc_geo_0008D0), // 0x0E0008D0
                  GEO_BRANCH(1, hmc_geo_000938), // 0x0E000938
                  GEO_BRANCH(1, hmc_geo_000998), // 0x0E000998
                  GEO_BRANCH(1, hmc_geo_000A18), // 0x0E000A18
                  GEO_BRANCH(1, hmc_geo_000A88), // 0x0E000A88
                  GEO_BRANCH(1, hmc_geo_000AE8), // 0x0E000AE8
                  GEO_BRANCH(1, hmc_geo_000B48), // 0x0E000B48
               GEO_CLOSE_NODE(),
               GEO_RENDER_OBJ(),
               GEO_ASM(0, geo_envfx_main),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
