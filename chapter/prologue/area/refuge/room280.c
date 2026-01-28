inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "East Barracks";
  long_desc =
    "The road ends near a heap of collapsed roof tiles. A rusted bell frame tilts\n"
    "in the rubble.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room279",
    "south" : "/chapter/prologue/area/refuge/room1201",
  ]);

  set_light(1);
}
