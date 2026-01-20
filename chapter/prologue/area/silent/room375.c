inherit "room/room";

void create() {
  ::create();

  short_desc = "Park End";
  long_desc = "The path ends at a low wall broken into piles of stone. Beyond it, the park\ngives way to rough ground.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room376", "east",
    "chapter/prologue/area/silent/room374", "south",
  });

  set_light(1);
}
