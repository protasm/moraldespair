#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET no_castle_flag = 1;
FOUR_EXIT(
    "domain/lp-245/room/vill_track", "west", "domain/lp-245/room/yard", "north", "domain/lp-245/room/narr_alley", "south",
    "domain/lp-245/room/vill_road2", "east", "Village road",
    "A long road going east through the village. The road narrows to a\n" +
        "track to the west. There is an alley to the north and the south.\n",
    1)
