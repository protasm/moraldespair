inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cracked Drop";
  long_desc = "The space broadens into a shallow, rubble-filled bowl where paths meet. Rust-red streaks mark where metal once lay, now long gone.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room103", "east",
  });

  set_light(1);
}
