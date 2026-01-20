inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park End";
  long_desc = "The path ends at a low wall broken into piles of stone. Beyond it, the park\ngives way to rough ground.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room376", "east",
    "chapter/prologue/area/silent/room374", "south",
  });
}
