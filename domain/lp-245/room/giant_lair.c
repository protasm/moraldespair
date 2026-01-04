#include "room.h"

object giant;

#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    if (!giant || !living(giant)) {                                            \
        giant = clone_object("obj/monster");                                   \
        giant->set_name("giant");                                              \
        giant->set_level(15);                                                  \
        giant->set_short("A giant");                                           \
        giant->set_wc(20);                                                     \
        giant->set_ac(2);                                                      \
        giant->set_aggressive(1);                                              \
        move_object(giant, this_object());                                     \
    }

TWO_EXIT("domain/lp-245/room/giant_path", "east", "domain/lp-245/room/giant_conf", "west",
         "Lair of the Giant", "There are mountains all around you.\n", 1)
