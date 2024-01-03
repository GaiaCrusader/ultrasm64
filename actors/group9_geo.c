#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "level_commands.h"

#include "make_const_nonconst.h"

#include "common1.h"
#include "group9.h"
#include "game/farcall_helpers.h"

#include "bookend/geo.inc.c"
#include "book/geo.inc.c"
#include "chair/geo.inc.c"
#include "mad_piano/geo.inc.c"
#include "boo/geo.inc.c"
#include "haunted_cage/geo.inc.c"

#include "game/behaviors/boo.inc.c"
#include "game/behaviors/flying_bookend_switch.inc.c"
#include "game/behaviors/haunted_chair.inc.c"
#include "game/behaviors/mad_piano.inc.c"
#include "game/behaviors/bbh_tilting_trap.inc.c"
#include "game/behaviors/bbh_haunted_bookshelf.inc.c"
#include "game/behaviors/bbh_merry_go_round.inc.c"

const LevelScript script_func_global_10[] = {
    LOAD_MODEL_FROM_GEO(MODEL_BOO,                     boo_geo),
    LOAD_MODEL_FROM_GEO(MODEL_HAUNTED_CHAIR,           haunted_chair_geo),
    LOAD_MODEL_FROM_GEO(MODEL_MAD_PIANO,               mad_piano_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOOKEND_PART,            bookend_part_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOOKEND,                 bookend_geo),
    LOAD_MODEL_FROM_GEO(MODEL_HAUNTED_CAGE,            haunted_cage_geo),
    RETURN(),
};