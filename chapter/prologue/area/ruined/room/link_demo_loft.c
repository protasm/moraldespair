inherit "/chapter/prologue/std/link_room";

void create() {
  string room_path;

  ::create();

  short_desc = "Loft Hatch";
  room_path = base_name(this_object());
  long_desc = room_path + "\n\n"
              "A low loft crouches above the antechamber, its beams warped and\n"
              "dry. A square trapdoor gapes in the floor, the only clear way "
              "back\n"
              "down. Use \"linkgo trapdoor\" to return to the hub.";

  add_link("trapdoor", "link_demo_hub");

  return;
}
