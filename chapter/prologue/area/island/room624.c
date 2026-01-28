inherit "/chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "East of the waterfall";
  long_desc = "East of the waterfall.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room623",
    "west" : "/chapter/prologue/area/island/room625",
  ]);

  set_light(1);
}
