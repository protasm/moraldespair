inherit "room/room";

void create() {
  ::create();


  short_desc = "West End of Balin Road";
  long_desc = "West End of Balin Road.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room638",
    "northeast" : "/chapter/prologue/area/island/room720",
    "east" : "/chapter/prologue/area/island/room636",
    "south" : "/chapter/prologue/area/island/room723",
  ]);

  set_light(1);
}
