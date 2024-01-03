#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group6.h"
#include "game/farcall_helpers.h"

#include "monty_mole/geo.inc.c"
#include "ukiki/geo.inc.c"
#include "fwoosh/geo.inc.c"

#include "game/behaviors/monty_mole.inc.c"    // TODO
#include "game/behaviors/ukiki.inc.c"
#include "game/behaviors/ukiki_cage.inc.c"

const LevelScript script_func_global_7[] = {
    LOAD_MODEL_FROM_DL( MODEL_DL_MONTY_MOLE_HOLE,      monty_mole_hole_seg5_dl_05000840, LAYER_TRANSPARENT_DECAL),
    LOAD_MODEL_FROM_GEO(MODEL_MONTY_MOLE,              monty_mole_geo),
    LOAD_MODEL_FROM_GEO(MODEL_UKIKI,                   ukiki_geo),
    LOAD_MODEL_FROM_GEO(MODEL_FWOOSH,                  fwoosh_geo),
    RETURN(),
};