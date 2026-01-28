inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Foyer";
  long_desc = "Foyer.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room684",
    "east" : "/chapter/prologue/area/island/room678",
    "north" : "/chapter/prologue/area/island/room680",
  ]);

  set_light(1);
}
