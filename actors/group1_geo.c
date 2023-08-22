#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group1.h"
#include "game/farcall_helpers.h"

#include "yellow_sphere_small/geo.inc.c"
#include "hoot/geo.inc.c"
#include "thwomp/geo.inc.c"
#include "bullet_bill/geo.inc.c"
#include "heave_ho/geo.inc.c"

#include "game/behaviors/hoot.inc.c"
#include "game/behaviors/bullet_bill.inc.c"
#include "game/behaviors/heave_ho.inc.c"

const LevelScript script_func_global_2[] = {
    LOAD_MODEL_FROM_GEO(MODEL_BULLET_BILL,             bullet_bill_geo),
    LOAD_MODEL_FROM_GEO(MODEL_YELLOW_SPHERE,           yellow_sphere_geo),
    LOAD_MODEL_FROM_GEO(MODEL_HOOT,                    hoot_geo),
    LOAD_MODEL_FROM_GEO(MODEL_THWOMP,                  thwomp_geo),
    LOAD_MODEL_FROM_GEO(MODEL_HEAVE_HO,                heave_ho_geo),
    RETURN(),
};