inherit "room/room";

void create() {
  ::create();


  short_desc = "Central Chamber";
  long_desc = "Central Chamber.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room715",
    "west" : "/chapter/prologue/area/island/room713",
  ]);

  set_light(1);
}
