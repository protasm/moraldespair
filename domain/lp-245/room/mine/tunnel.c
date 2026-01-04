#include "/room/std.h"
#undef EXTRA_LONG
#define EXTRA_LONG                                                             \
    if (id(str)) {                                                             \
        write("WARNING !!\n\n" +                                               \
              "The mines are closed due to risk of falling rock.\n");          \
        return;                                                                \
    }

int id(string str) {
    return str == "sign" || str == "pole";
}

TWO_EXIT("domain/lp-245/room/mount_pass", "south", "domain/lp-245/room/mine/tunnel2", "north",
         "Mine entrance",
         "This is the entrance to the mines.\nThere is a sign on a pole.\n", 1)
