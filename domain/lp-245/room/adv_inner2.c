#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    if (!arg) {                                                                \
        move_object(clone_object("domain/lp-245/obj/wiz_bull_board2"), this_object());       \
    }

ONE_EXIT("domain/lp-245/room/adv_inner", "north", "The LPC board",
         "This is the LPC discussion room.\n" +
             "Only wizards can access this room.\n",
         1)
