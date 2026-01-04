#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    no_castle_flag = 1;                                                        \
    if (!present("stick")) {                                                   \
        object stick;                                                          \
        stick = clone_object("domain/lp-245/obj/torch");                                     \
        move_object(stick, "domain/lp-245/room/hump");                                       \
        stick->set_name("stick");                                              \
        stick->set_fuel(500);                                                  \
        stick->set_weight(1);                                                  \
    }                                                                          \
    if (!present("money")) {                                                   \
        object money;                                                          \
        money = clone_object("obj/money");                                     \
        move_object(money, "domain/lp-245/room/hump");                                       \
        money->set_money(10);                                                  \
    }

TWO_EXIT("domain/lp-245/room/vill_green", "east", "domain/lp-245/room/wild1", "west", "Humpbacked bridge",
         "An old humpbacked bridge.\n", 1)
