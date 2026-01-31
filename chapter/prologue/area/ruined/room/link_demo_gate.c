inherit "/chapter/prologue/std/link_room";

void create() {
  string room_path;

  ::create();

  short_desc = "Caged Hall";
  room_path = base_name(this_object());
  long_desc = room_path + "\n\n"
              "This room is the destination for the east link when the gate "
              "is open.\n"
              "If you can reach it, use \"linkgo west\" to return to the "
              "hub.";

  add_link("west", "link_demo_hub");

  return;
}
