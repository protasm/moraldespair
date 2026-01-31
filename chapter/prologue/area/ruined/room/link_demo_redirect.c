inherit "/chapter/prologue/std/link_room";

#include <link.h>

void create() {
  ::create();

  short_desc = "Tilting Passage";
  long_desc = "This room demonstrates a link that redirects you to another "
              "room\n"
              "after entry. Use \"linkgo down\" from the hub to trigger the "
              "redirect.";

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
