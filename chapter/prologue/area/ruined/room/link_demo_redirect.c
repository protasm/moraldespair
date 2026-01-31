inherit "/chapter/prologue/std/link_room";

#include <link.h>

void create() {
  ::create();

  short_desc = "Tilting Passage";
  long_desc = "The passage dips sharply under a crust of fallen stone, its\n"
              "centerline worn smooth. A dark seam cuts across the floor "
              "where the\n"
              "slab has begun to shift.";

  add_link("up", "link_demo_hub");

  return;
}

mapping link_on_enter(object actor, object origin, object link) {
  mapping result;

  result = ([
    LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW_REDIRECT,
    LINK_RESULT_MESSAGE : "The floor gives, spilling the traveler into a "
                          "lower vault.",
    LINK_RESULT_REDIRECT : "/chapter/prologue/area/ruined/room/link_demo_redirect_target"
  ]);

  return result;
}
