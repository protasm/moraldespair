#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

object tracer;

void extra_reset() {
    if (!tracer) {
        tracer = clone_object("/domain/lp-245/obj/trace");
        move_object(tracer, this_object());
    }
}

ONE_EXIT("domain/lp-245/room/church", "church", "Lars's residence",
         "This is the residence of Lars.\n", 1)
