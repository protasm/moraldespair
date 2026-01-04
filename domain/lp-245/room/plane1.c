#include "room.h"
object wolf;

#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    if (!wolf) {                                                               \
        wolf = clone_object("obj/monster");                                    \
        wolf->set_name("wolf");                                                \
        wolf->set_level(3);                                                    \
        wolf->set_short("A wolf");                                             \
        wolf->set_long("A grey wolf running around. It has\n" +                \
                       "some big dangerous teeth.\n");                         \
        wolf->set_wc(7);                                                       \
        wolf->set_move_at_reset();                                             \
        wolf->set_whimpy();                                                    \
        move_object(wolf, "domain/lp-245/room/ruin");                                        \
    }

TWO_EXIT("domain/lp-245/room/clearing", "south", "domain/lp-245/room/plane2", "north", "A large open plain",
         "A large open plain, extending to north and south.\n", 1)
