#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group3.h"
#include "game/farcall_helpers.h"

#include "king_bobomb/geo.inc.c"
#include "water_bubble/geo.inc.c"

#include "game/behaviors/king_bobomb.inc.c"
#include "game/behaviors/water_bomb.inc.c" // TODO: Shadow position
#include "game/behaviors/water_bomb_cannon.inc.c"

const LevelScript script_func_global_4[] = {
    LOAD_MODEL_FROM_GEO(MODEL_WATER_BOMB,              water_bomb_geo),
    LOAD_MODEL_FROM_GEO(MODEL_WATER_BOMB_SHADOW,       water_bomb_shadow_geo),
    LOAD_MODEL_FROM_GEO(MODEL_KING_BOBOMB,             king_bobomb_geo),
    RETURN(),
};