inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Central slave bazaar";
  long_desc = "Central slave bazaar.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room728",
    "east" : "/chapter/prologue/area/island/room731",
    "south" : "/chapter/prologue/area/island/room733",
  ]);

  set_light(1);
}
