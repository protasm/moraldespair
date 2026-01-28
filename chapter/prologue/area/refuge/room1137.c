inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Upper Landing";
  long_desc =
    "The landing opens onto two dark passages with flaked plaster. A fallen torch\n"
    "bracket lies on the floor.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1136",
    "east" : "/chapter/prologue/area/refuge/room1142",
    "up" : "/chapter/prologue/area/refuge/room1138",
  ]);

  set_light(1);
}
