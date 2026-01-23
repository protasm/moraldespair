inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Hut";
  long_desc = "Dwarven Hut.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room644",
  ]);

  set_light(1);
}
