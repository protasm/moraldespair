inherit "/chapter/prologue/std/link_room";

void create() {
  object link, gate;
  string origin_id;

  ::create();

  short_desc = "Bare Antechamber";
  long_desc = "This room demonstrates basic link exits. Use \"linkgo <direction>\" (for example, \"linkgo north\") to try north, west, down, east, or door. The east link is gated so you can see the blocked traversal message.";

  add_link("north", "link_demo_clear");
  add_link("west", "link_demo_guard");
  add_link("down", "link_demo_redirect");
  add_link("door", "link_demo_loft");

  link = add_link("east", "link_demo_gate");
  origin_id = base_name(this_object());

  if (objectp(link)) {
    gate = new("/core/link_gate");
    gate->set_name("rusted grille");
    gate->set_closed_message("A rusted grille bars the passage.");
    gate->set_open(0);

    link->add_gate(origin_id, gate);
  }

  return;
}
