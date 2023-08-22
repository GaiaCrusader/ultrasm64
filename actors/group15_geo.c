#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group15.h"
#include "game/farcall_helpers.h"

#include "lakitu_cameraman/geo.inc.c"
#include "toad/geo.inc.c"
#include "mips/geo.inc.c"
#include "boo_castle/geo.inc.c"

#include "game/behaviors/boo_cage.inc.c"
#include "game/behaviors/boo_castle.inc.c"
#include "game/behaviors/camera_lakitu.inc.c" // TODO: 104 label, follow cam documentation
#include "game/behaviors/mips.inc.c"

const LevelScript script_func_global_16[] = {
    LOAD_MODEL_FROM_GEO(MODEL_MIPS,                    mips_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOO_CASTLE,              boo_castle_geo),
    LOAD_MODEL_FROM_GEO(MODEL_LAKITU,                  lakitu_geo),
    LOAD_MODEL_FROM_GEO(MODEL_TOAD,                    toad_geo),
    RETURN(),
};