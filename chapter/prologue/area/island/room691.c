inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Power System Generator";
  long_desc = "Power System Generator.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room692",
    "west" : "/chapter/prologue/area/island/room618",
  ]);

  set_light(1);
}
