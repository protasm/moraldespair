inherit "/chapter/prologue/std/link_room";

void create() {
  object link;
  object gate;
  string origin_id;

  ::create();

  short_desc = "Bare Antechamber";
  long_desc = "This room demonstrates basic link exits. Use \"linkgo "
              "<direction>\"\n"
              "(for example, \"linkgo north\") to try north, west, down, "
              "or east.\n"
              "The east link is gated so you can see the blocked traversal "
              "message.";

  link = add_link("north", "link_demo_clear");
  add_link("west", "link_demo_guard");
  add_link("down", "link_demo_redirect");

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
