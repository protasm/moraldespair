inherit "room/room";

void create() {
  ::create();

  short_desc = "West Crossing";
  long_desc =
    "The intersection is marked by a low stone post worn smooth. Thin grass pushes\n"
    "up through the central joints.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room261",
    "east" : "/chapter/prologue/area/refuge/room259",
    "north" : "/chapter/prologue/area/refuge/room264",
  ]);

  set_light(1);
}
