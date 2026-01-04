#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    if (!arg) {                                                                \
        move_object(clone_object("domain/lp-245/obj/wiz_bull_board"), this_object());        \
    }

TWO_EXIT("domain/lp-245/room/adv_guild", "north", "domain/lp-245/room/adv_inner2", "south",
         "The inner room of adventurers guild",
         "This is the inner room of adventures guild. If you want to discuss "
         "LPC,\n" +
             "then move to the room south from here.\n" +
             "Only wizards can access this room.\n",
         1)
