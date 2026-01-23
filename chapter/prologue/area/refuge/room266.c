inherit "room/room";

void create() {
  ::create();

  short_desc = "High Road";
  long_desc =
    "The road climbs slightly, flanked by taller facades. Broken balcony ironwork\n"
    "hangs over the street.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room265",
    "north" : "/chapter/prologue/area/refuge/room267",
  ]);

  set_light(1);
}
