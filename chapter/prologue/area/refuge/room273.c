inherit "/room/room";

void create() {
  ::create();

  short_desc = "North Spur";
  long_desc =
    "The road narrows as the surrounding walls thin. A fragment of mosaic tile\n"
    "glints among the dust.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room267",
    "northwest" : "/chapter/prologue/area/refuge/room1202",
    "north" : "/chapter/prologue/area/refuge/room274",
  ]);

  set_light(1);
}
