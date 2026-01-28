inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Elderoak's Quarters";
  long_desc = "Elderoak's Quarters.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/island/room632",
  ]);

  set_light(1);
}
