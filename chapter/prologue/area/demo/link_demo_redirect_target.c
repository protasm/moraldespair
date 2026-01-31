inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Lower Vault";
  long_desc = "This room is the redirect destination for the down link from the hub. Use \"linkgo up\" to return to the passage.";

  add_link("up", "link_demo_hub");

  return;
}
