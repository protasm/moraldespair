inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Open Landing";
  long_desc = "This room demonstrates a basic link that allows movement "
              "without\n"
              "any special behavior. Use \"linkgo south\" to return to the "
              "hub.";

  add_link("south", "link_demo_hub");

  return;
}
