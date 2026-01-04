#include "/room/std.h"

int id(string str) {
    if (str == "ruin")
        return 1;
    else
        return 0;
}

FOUR_EXIT("domain/lp-245/room/plane4", "south", "domain/lp-245/room/plane8", "north", "domain/lp-245/room/plane9", "east",
          "domain/lp-245/room/plane3", "west", "Ruin",
          "A very old looking ruin. There is no roof, and no door.\n", 1)
