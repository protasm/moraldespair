inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Chamber";
  long_desc =
    "The chamber is broad but empty, with a roof caved in at one end. Charred beams\n"
    "lie across the floor.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1160",
    "west" : "/chapter/prologue/area/refuge/room1162",
  ]);

  set_light(1);
}
