inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Open Landing";
  long_desc = "A broad landing holds only fractured tiles and the last "
              "scraps\n"
              "of a faded mosaic. A torn archway to the south frames the "
              "empty\n"
              "antechamber.";

  add_link("south", "link_demo_hub");

  return;
}
