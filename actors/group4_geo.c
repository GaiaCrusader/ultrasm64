#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group4.h"
#include "game/farcall_helpers.h"

#include "clam_shell/geo.inc.c"
#include "sushi/geo.inc.c"
#include "unagi/geo.inc.c"

#include "game/behaviors/clam.inc.c"
#include "game/behaviors/sushi.inc.c"
#include "game/behaviors/unagi.inc.c"
#include "game/behaviors/whirlpool.inc.c"

const LevelScript script_func_global_5[] = {
    LOAD_MODEL_FROM_GEO(MODEL_MANTA_RAY,               manta_seg5_geo_05008D14),
    LOAD_MODEL_FROM_GEO(MODEL_UNAGI,                   unagi_geo),
    LOAD_MODEL_FROM_GEO(MODEL_SUSHI,                   sushi_geo),
    LOAD_MODEL_FROM_DL( MODEL_DL_WHIRLPOOL,            whirlpool_seg5_dl_05013CB8, LAYER_TRANSPARENT),
    LOAD_MODEL_FROM_GEO(MODEL_CLAM_SHELL,              clam_shell_geo),
    RETURN(),
};