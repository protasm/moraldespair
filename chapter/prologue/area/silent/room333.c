inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Threshold";
  long_desc = "Wide steps lead up to a carved facade streaked with rain. The doorway stands\nopen, its lintel chipped and scarred.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room317",
    "north":"/chapter/prologue/area/silent/room920",
  ]);

  set_light(1);
}
