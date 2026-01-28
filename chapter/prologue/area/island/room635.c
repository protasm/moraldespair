inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "northwest" : "/chapter/prologue/area/island/room719",
    "south" : "/chapter/prologue/area/island/room717",
    "northeast" : "/chapter/prologue/area/island/room718",
    "east" : "/chapter/prologue/area/island/room610",
    "west" : "/chapter/prologue/area/island/room636",
  ]);

  set_light(1);
}
