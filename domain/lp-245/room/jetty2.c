#include "room.h"

/* no castle drop here... its a jetty, how can anything be placed north &
   south of here... there is nothing but water around, place it in sea */
#undef EXTRA_RESET
#define EXTRA_RESET                                                            \
    no_castle_flag = 1;                                                        \
    if (!present("bag"))                                                       \
        move_object(clone_object("domain/lp-245/obj/bag"), this_object());

TWO_EXIT("domain/lp-245/room/vill_shore2", "west", "domain/lp-245/room/sea", "east", "Jetty",
         "You are at a jetty. The waves rolls in from east.\nA small path "
         "leads back to west.\n",
         1)
