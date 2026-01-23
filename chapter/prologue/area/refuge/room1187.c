inherit "room/room";

void create() {
  ::create();

  short_desc = "Shuttered Street";
  long_desc =
    "Tall shutters hang open or lie broken along the street. A few carved lintels\n"
    "remain, softened by weather.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room1188",
    "west" : "/chapter/prologue/area/refuge/room1186",
  ]);

  set_light(1);
}
