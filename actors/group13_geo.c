#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group13.h"
#include "game/farcall_helpers.h"

#include "skeeter/geo.inc.c"
#include "seaweed/geo.inc.c"
#include "cyan_fish/geo.inc.c"
#include "bub/geo.inc.c"
#include "water_ring/geo.inc.c"
#include "treasure_chest/geo.inc.c"

#include "game/behaviors/skeeter.inc.c"
#include "game/behaviors/seaweed.inc.c"
#include "game/behaviors/bub.inc.c"
#include "game/behaviors/water_ring.inc.c"
#include "game/behaviors/treasure_chest.inc.c"

const LevelScript script_func_global_14[] = {
    LOAD_MODEL_FROM_GEO(MODEL_BUB,                     bub_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TREASURE_CHEST_BASE,     treasure_chest_base_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TREASURE_CHEST_LID,      treasure_chest_lid_geo),
    LOAD_MODEL_FROM_GEO(MODEL_CYAN_FISH,               cyan_fish_geo),
    LOAD_MODEL_FROM_GEO(MODEL_WATER_RING,              water_ring_geo),
    LOAD_MODEL_FROM_GEO(MODEL_SEAWEED,                 seaweed_geo),
    LOAD_MODEL_FROM_GEO(MODEL_SKEETER,                 skeeter_geo),
    RETURN(),
};