inherit "/room/room";

void create() {
  ::create();

  short_desc = "West Post";
  long_desc =
    "A small guard nook overlooks the outer road, its slit windows broken and\n"
    "widened by time. Dusty stone benches remain where sentries once rested.\n";
  dest_dir = ([
    "up" : "/chapter/prologue/area/refuge/room1136",
    "northeast" : "/chapter/prologue/area/refuge/room237",
  ]);

  set_light(1);
}
