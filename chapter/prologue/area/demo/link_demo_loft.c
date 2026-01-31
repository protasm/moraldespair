inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Loft Hatch";
  long_desc = "A low loft crouches above the antechamber, its beams warped and dry. A square trapdoor gapes in the floor, the only clear way back down. Use \"linkgo trapdoor\" to return to the hub.";

  add_link("trapdoor", "link_demo_hub");

  return;
}
