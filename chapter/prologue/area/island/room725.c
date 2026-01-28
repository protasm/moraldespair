inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Bazaar Crossroad";
  long_desc = "Bazaar Crossroad.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/island/room726",
    "east" : "/chapter/prologue/area/island/room729",
    "north" : "/chapter/prologue/area/island/room724",
  ]);

  set_light(1);
}
