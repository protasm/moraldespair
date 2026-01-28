inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "A cramped room opens off the hall, empty of comforts. Scratches line the wall\nwhere wood once hung.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room362",
  ]);

  set_light(1);
}
