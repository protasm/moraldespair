inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cracked Drop";
  long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red streaks mark where metal once lay, now long gone.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room1030", "south",
    "chapter/prologue/area/sunken/room28", "east",
    "chapter/prologue/area/sunken/room30", "west",
  });

  set_light(1);
}
