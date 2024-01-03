#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group7.h"
#include "game/farcall_helpers.h"

#include "spindrift/geo.inc.c"
#include "penguin/geo.inc.c"
#include "snowman/geo.inc.c"

#include "game/behaviors/spindrift.inc.c"
#include "game/behaviors/tuxie.inc.c"
#include "game/behaviors/racing_penguin.inc.c"
#include "game/behaviors/sl_walking_penguin.inc.c"
#include "game/behaviors/snowman.inc.c"
#include "game/behaviors/mr_blizzard.inc.c"

const LevelScript script_func_global_8[] = {
    LOAD_MODEL_FROM_GEO(MODEL_SPINDRIFT,               spindrift_geo),
    LOAD_MODEL_FROM_GEO(MODEL_MR_BLIZZARD_HIDDEN,      mr_blizzard_hidden_geo),
    LOAD_MODEL_FROM_GEO(MODEL_MR_BLIZZARD,             mr_blizzard_geo),
    LOAD_MODEL_FROM_GEO(MODEL_PENGUIN,                 penguin_geo),
    RETURN(),
};
