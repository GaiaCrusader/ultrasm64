#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group11.h"
#include "game/farcall_helpers.h"

#include "bubba/geo.inc.c"
#include "wiggler_head/geo.inc.c"
#include "lakitu_enemy/geo.inc.c"
#include "spiny_egg/geo.inc.c"
#include "spiny/geo.inc.c"

#include "game/behaviors/bubba.inc.c"
#include "game/behaviors/wiggler.inc.c"     // TODO
#include "game/behaviors/enemy_lakitu.inc.c" // TODO
#include "game/behaviors/spiny.inc.c"

const LevelScript script_func_global_12[] = {
    LOAD_MODEL_FROM_GEO(MODEL_ENEMY_LAKITU,            enemy_lakitu_geo),
    LOAD_MODEL_FROM_GEO(MODEL_SPINY_BALL,              spiny_ball_geo),
    LOAD_MODEL_FROM_GEO(MODEL_SPINY,                   spiny_geo),
    LOAD_MODEL_FROM_GEO(MODEL_WIGGLER_HEAD,            wiggler_head_geo),
    LOAD_MODEL_FROM_GEO(MODEL_WIGGLER_BODY,            wiggler_body_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BUBBA,                   bubba_geo),
    RETURN(),
};