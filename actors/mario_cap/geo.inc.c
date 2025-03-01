// 0x16000CA4
const GeoLayout marios_cap_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_9_VERTS, 0xB4, 75),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ASM(10, geo_update_layer_transparency),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_seg3_dl_03022F48),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_seg3_dl_03022F48),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000CF0
const GeoLayout marios_metal_cap_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_9_VERTS, 0xB4, 75),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ASM(10, geo_update_layer_transparency),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_seg3_dl_03022FF8),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_seg3_dl_03022FF8),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000D3C
const GeoLayout marios_wing_cap_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_9_VERTS, 0xB4, 75),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ASM(10, geo_update_layer_transparency),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
            GEO_NODE_START(),
            GEO_OPEN_NODE(),
               GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_seg3_dl_03022F48),
               GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_seg3_dl_030230B0),
            GEO_CLOSE_NODE(),
            GEO_NODE_START(),
            GEO_OPEN_NODE(),
               GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_seg3_dl_03023160),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16000DA8
const GeoLayout marios_winged_metal_cap_geo[] = {
};
