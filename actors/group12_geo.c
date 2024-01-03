#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group12.h"
#include "game/farcall_helpers.h"

#include "bowser_flame/geo.inc.c"
#include "impact_ring/geo.inc.c"
#include "yellow_sphere/geo.inc.c"
#include "bowser/geo.inc.c"
#include "bomb/geo.inc.c"
#include "impact_smoke/geo.inc.c"

#include "game/behaviors/bowser_flame.inc.c"
#include "game/behaviors/grand_star.inc.c"
#include "game/behaviors/bowser.inc.c"
#include "game/behaviors/bowser_falling_platform.inc.c"
#include "game/behaviors/bowser_bomb.inc.c"
#include "game/behaviors/shock_wave.inc.c"

const LevelScript script_func_global_13[] = {
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER,                  bowser_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_BOMB_CHILD_OBJ,   bowser_bomb_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_BOMB,             bowser_bomb_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_SMOKE,            bowser_impact_smoke_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_FLAMES,           bowser_flames_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_WAVE,             invisible_bowser_accessory_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOWSER_NO_SHADOW,        bowser_geo_no_shadow),
    RETURN(),
};