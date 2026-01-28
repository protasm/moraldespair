inherit "/room/room";

void create() {
  ::create();

  short_desc = "Arcade Row";
  long_desc =
    "Shallow arcades line the street, their arches chipped and stained. Bits of\n"
    "colored tile still cling to the lower walls.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1185",
    "east" : "/chapter/prologue/area/refuge/room1187",
    "north" : "/chapter/prologue/area/refuge/room1190",
  ]);

  set_light(1);
}
