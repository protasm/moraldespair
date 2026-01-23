inherit "room/room";

void create() {
  ::create();


  short_desc = "Temple Plaza";
  long_desc = "Temple Plaza.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room715",
    "east" : "/chapter/prologue/area/island/room671",
    "south" : "/chapter/prologue/area/island/room662",
  ]);

  set_light(1);
}
