inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Walk";
  long_desc = "A long walk stretches across a quiet quadrangle. The air is still beneath\ntall, weathered walls.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room898",
    "north":"/chapter/prologue/area/silent/room896",
  ]);

  set_light(1);
}
