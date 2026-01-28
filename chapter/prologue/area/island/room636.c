inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Balin Road";
  long_desc = "Balin Road.\n";
  dest_dir = ([
    "southwest" : "/chapter/prologue/area/island/room722",
    "east" : "/chapter/prologue/area/island/room635",
    "southeast" : "/chapter/prologue/area/island/room721",
    "west" : "/chapter/prologue/area/island/room637",
  ]);

  set_light(1);
}
