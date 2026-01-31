inherit "/chapter/prologue/std/link_room";

#include <link.h>

void create() {
  ::create();

  short_desc = "Guarded Shelf";
  long_desc = "A raised shelf of stone overlooks the antechamber, marked "
              "by the\n"
              "scraped tracks of something once stationed here. Broken "
              "shield\n"
              "plates lie in a loose fan against the wall.";

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
