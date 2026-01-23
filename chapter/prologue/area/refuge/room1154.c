inherit "room/room";

void create() {
  ::create();

  short_desc = "East Post";
  long_desc =
    "A guard niche watches the road through a broken arrow slit. The ledge is slick\n"
    "with damp and moss.\n";
  dest_dir = ([
    "northwest" : "/chapter/prologue/area/refuge/room237",
    "east" : "/chapter/prologue/area/refuge/room1155",
  ]);

  set_light(1);
}
