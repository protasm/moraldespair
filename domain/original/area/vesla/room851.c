inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Quiet Bunks";
  long_desc = "Rough bunks sag against the walls, silent in dust, rot, and mildew. Hooks and pegs hang over a sagging floor, hinting at lodging long abandoned.";
  dest_dir = ({
    "domain/original/area/vesla/room850", "south",
  });
}
