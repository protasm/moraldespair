inherit "room/room";

void create() {
  ::create();


  short_desc = "Entryway";
  long_desc = "Entryway.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room677",
    "south" : "/chapter/prologue/area/island/room694",
    "north" : "/chapter/prologue/area/island/room696",
  ]);

  set_light(1);
}
