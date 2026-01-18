inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park End";
  long_desc = "The path ends at a low wall broken into piles of stone. Beyond it, the park\ngives way to rough ground.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room376", "east",
    "domain/original/area/exedoria/room374", "south",
  });
}
