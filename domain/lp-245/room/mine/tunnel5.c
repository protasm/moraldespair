#include "/room/std.h"

#undef EXTRA_LONG
#define EXTRA_LONG                                                             \
    if (str == "table" || str == "stone table") {                              \
        write("You see nothing special about it.\n");                          \
        return;                                                                \
    }

TWO_EXIT("domain/lp-245/room/mine/tunnel4", "south", "domain/lp-245/room/mine/tunnel_room", "north",
         "Stone table",
         "In the tunnel into the mines.\n" +
             "There is a big stone table here.\n",
         0)

int id(string str) {
    return str == "table" || str == "stone table";
}
