inherit "/chapter/prologue/std/link_room";

void create() {
  string room_path;

  ::create();

  short_desc = "Open Landing";
  room_path = base_name(this_object());
  long_desc = room_path + "\n\n"
              "This room demonstrates a basic link that allows movement "
              "without\n"
              "any special behavior. Use \"linkgo south\" to return to the "
              "hub.";

  add_link("south", "link_demo_hub");

  return;
}
