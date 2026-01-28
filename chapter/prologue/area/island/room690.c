inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Entrance to the Hall of Records";
  long_desc = "Entrance to the Hall of Records.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room617",
  ]);

  set_light(1);
}
