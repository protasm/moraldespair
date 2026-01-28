inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Crowded Thoroughfare";
  long_desc = "Crowded Thoroughfare.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room724",
    "north" : "/chapter/prologue/area/island/room637",
  ]);

  set_light(1);
}
