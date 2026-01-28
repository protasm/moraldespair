inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Park End";
  long_desc = "The path ends at a low wall broken into piles of stone. Beyond it, the park\ngives way to rough ground.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room376",
    "south":"/chapter/prologue/area/silent/room374",
  ]);

  set_light(1);
}
