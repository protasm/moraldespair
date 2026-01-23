inherit "room/room";

void create() {
  ::create();

  short_desc = "Lonely Row";
  long_desc =
    "Shuttered storefronts line the way, their thresholds choked with weeds. The\n"
    "stone is slick where rainwater pools.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room255",
    "north" : "/chapter/prologue/area/refuge/room257",
  ]);

  set_light(1);
}
