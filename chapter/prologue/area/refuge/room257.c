inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Row";
  long_desc =
    "Faded plaster clings to the walls in torn patches. A thin vine threads across\n"
    "a cracked arch.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room256",
    "north" : "/chapter/prologue/area/refuge/room258",
  ]);

  set_light(1);
}
