inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Shack";
  long_desc = "Dwarven Shack.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room648",
  ]);

  set_light(1);
}
