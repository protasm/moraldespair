inherit "/chapter/prologue/std/link_room";

void create() {
  ::create();

  short_desc = "Caged Hall";
  long_desc = "The hall narrows into a cage of warped iron ribs, bent "
              "inward by\n"
              "long pressure. Rust flakes gather beneath the metal, "
              "muffling each\n"
              "step.";

  add_link("west", "link_demo_hub");

  return;
}
