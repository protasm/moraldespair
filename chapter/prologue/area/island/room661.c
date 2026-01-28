inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room660",
    "east" : "/chapter/prologue/area/island/room662",
    "south" : "/chapter/prologue/area/island/room673",
  ]);

  set_light(1);
}
