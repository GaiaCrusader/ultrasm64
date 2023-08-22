#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "common0.h"
#include "game/farcall_helpers.h"

#include "blue_coin_switch/geo.inc.c"
#include "amp/geo.inc.c"
#include "cannon_lid/geo.inc.c"
#include "cannon_base/geo.inc.c"
#include "cannon_barrel/geo.inc.c"
#include "chuckya/geo.inc.c"
#include "purple_switch/geo.inc.c"
#include "checkerboard_platform/geo.inc.c"
#include "heart/geo.inc.c"
#include "flyguy/geo.inc.c"
#include "breakable_box/geo.inc.c"
#include "bowling_ball/geo.inc.c"
#include "exclamation_box/geo.inc.c"
#include "goomba/geo.inc.c"
#include "bobomb/geo.inc.c"
#include "metal_box/geo.inc.c"
#include "exclamation_box_outline/geo.inc.c"
#include "koopa_shell/geo.inc.c"

#include "game/behaviors/blue_coin.inc.c"
#include "game/behaviors/amp.inc.c"
#include "game/behaviors/cannon.inc.c"
#include "game/behaviors/cannon_door.inc.c"
#include "game/behaviors/chuckya.inc.c"
#include "game/behaviors/purple_switch.inc.c"
#include "game/behaviors/checkerboard_platform.inc.c"
#include "game/behaviors/recovery_heart.inc.c"
#include "game/behaviors/fly_guy.inc.c"
#include "game/behaviors/breakable_box.inc.c"
#include "game/behaviors/bowling_ball.inc.c"
#include "game/behaviors/exclamation_box.inc.c"
#include "game/behaviors/goomba.inc.c"
#include "game/behaviors/bobomb.inc.c"
#include "game/behaviors/metal_box.inc.c"
#include "game/behaviors/koopa_shell.inc.c"
#include "game/behaviors/koopa_shell_underwater.inc.c"
#include "game/behaviors/koopa.inc.c" // TODO: Text arg field name
#include "game/behaviors/jumping_box.inc.c"
#include "game/behaviors/switch_hidden_objects.inc.c"
#include "game/behaviors/fire_spitter.inc.c"
#include "game/behaviors/breakable_box_small.inc.c"
#include "game/behaviors/falling_rising_platform.inc.c"
#include "game/behaviors/grill_door.inc.c"

#include "game/behaviors/sliding_platform.inc.c"
#include "game/behaviors/rolling_log.inc.c"
#include "game/behaviors/floating_platform.inc.c"
#include "game/behaviors/platform_on_track.inc.c"
#include "game/behaviors/seesaw_platform.inc.c"
#include "game/behaviors/ferris_wheel.inc.c"
#include "game/behaviors/sliding_platform_2.inc.c"
#include "game/behaviors/rotating_octagonal_plat.inc.c"
#include "game/behaviors/animated_floor_switch.inc.c"
#include "game/behaviors/activated_bf_plat.inc.c"
#include "game/behaviors/rotating_platform.inc.c"
#include "game/behaviors/square_platform_cycle.inc.c"
#include "game/behaviors/tilting_inverted_pyramid.inc.c"
#include "game/behaviors/bully.inc.c"
#include "game/behaviors/thwomp.inc.c"

const LevelScript script_func_global_1[] = {
    LOAD_MODEL_FROM_GEO(MODEL_BLUE_COIN_SWITCH,        blue_coin_switch_geo),
    LOAD_MODEL_FROM_GEO(MODEL_AMP,                     dAmpGeo),
    LOAD_MODEL_FROM_GEO(MODEL_PURPLE_SWITCH,           purple_switch_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CHECKERBOARD_PLATFORM,   checkerboard_platform_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BREAKABLE_BOX,           breakable_box_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BREAKABLE_BOX_SMALL,     breakable_box_small_geo),
    LOAD_MODEL_FROM_GEO(MODEL_EXCLAMATION_BOX_OUTLINE, exclamation_box_outline_geo),
    LOAD_MODEL_FROM_GEO(MODEL_EXCLAMATION_BOX,         exclamation_box_geo),
    LOAD_MODEL_FROM_GEO(MODEL_GOOMBA,                  goomba_geo),
    LOAD_MODEL_FROM_DL( MODEL_EXCLAMATION_POINT,       exclamation_box_outline_seg8_dl_08025F08, LAYER_ALPHA),
    LOAD_MODEL_FROM_GEO(MODEL_KOOPA_SHELL,             koopa_shell_geo),
    LOAD_MODEL_FROM_GEO(MODEL_METAL_BOX,               metal_box_geo),
    LOAD_MODEL_FROM_DL( MODEL_METAL_BOX_DL,            metal_box_dl,                             LAYER_OPAQUE),
    LOAD_MODEL_FROM_GEO(MODEL_BLACK_BOBOMB,            black_bobomb_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOBOMB_BUDDY,            bobomb_buddy_geo),
    LOAD_MODEL_FROM_DL( MODEL_DL_CANNON_LID,           cannon_lid_seg8_dl_080048E0,              LAYER_OPAQUE),
    LOAD_MODEL_FROM_GEO(MODEL_BOWLING_BALL,            bowling_ball_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CANNON_BARREL,           cannon_barrel_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CANNON_BASE,             cannon_base_geo),
    LOAD_MODEL_FROM_GEO(MODEL_HEART,                   heart_geo),
    LOAD_MODEL_FROM_GEO(MODEL_FLYGUY,                  flyguy_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CHUCKYA,                 chuckya_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TRAJECTORY_MARKER_BALL,      bowling_ball_track_geo),
    RETURN(),
};