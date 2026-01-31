inherit "/chapter/prologue/std/link_room";

#include <link.h>

void create() {
  string room_path;

  ::create();

  short_desc = "Guarded Shelf";
  room_path = base_name(this_object());
  long_desc = room_path + "\n\n"
              "This room demonstrates a link that allows entry but "
              "immediately\n"
              "reverses you with a message. Use \"linkgo west\" from the "
              "hub\n"
              "to trigger the reversal.";

  add_link("east", "link_demo_hub");

  return;
}

mapping link_on_enter(object actor, object origin, object link) {
  mapping result;

  result = ([
    LINK_RESULT_OUTCOME : LINK_OUTCOME_ALLOW_REVERSE,
    LINK_RESULT_MESSAGE : "A silent guard shape lurches from the debris "
                          "and drives the intruder back."
  ]);

  return result;
}
