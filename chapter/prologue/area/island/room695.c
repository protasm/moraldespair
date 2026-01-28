inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Guard Post";
  long_desc = "Guard Post.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/island/room694",
  ]);

  set_light(1);
}
