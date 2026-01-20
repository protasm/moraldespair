inherit "room/room";

void create() {
  ::create();

  short_desc = "West Post";
  long_desc =
    "A small guard nook overlooks the outer road, its slit windows broken and\n"
    "widened by time. Dusty stone benches remain where sentries once rested.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1136", "up",
    "chapter/prologue/area/anshelm/room237", "northeast",
  });

  set_light(1);
}
