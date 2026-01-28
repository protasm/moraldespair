inherit "/room/room";

void create() {
  ::create();

  short_desc = "Cracked Drop";
  long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red streaks mark where metal once lay, now long gone.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room99", "north",
    "chapter/prologue/area/sunken/room101", "south",
    "chapter/prologue/area/sunken/room997", "east",
    "chapter/prologue/area/sunken/room505", "west",
  });

  set_light(1);
}
