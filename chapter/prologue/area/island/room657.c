inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Keep Of Alcibiades";
  long_desc = "Keep Of Alcibiades.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room659",
    "east" : "/chapter/prologue/area/island/room658",
    "north" : "/chapter/prologue/area/island/room640",
  ]);

  set_light(1);
}
