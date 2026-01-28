inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Ruins";
  long_desc = "Ruins.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room627",
    "west" : "/chapter/prologue/area/island/room606",
  ]);

  set_light(1);
}
