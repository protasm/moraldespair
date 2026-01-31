inherit "/chapter/prologue/std/link_room";

void create() {
  string room_path;

  ::create();

  short_desc = "Lower Vault";
  room_path = base_name(this_object());
  long_desc = room_path + "\n\n"
              "This room is the redirect destination for the down link from "
              "the hub.\n"
              "Use \"linkgo up\" to return to the passage.";

  add_link("up", "link_demo_redirect");

  return;
}
