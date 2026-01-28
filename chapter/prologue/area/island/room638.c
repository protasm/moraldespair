inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Tunnel Under Canal";
  long_desc = "Tunnel Under Canal.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room637",
    "west" : "/chapter/prologue/area/island/room639",
  ]);

  set_light(1);
}
