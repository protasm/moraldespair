inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Pit";
  long_desc =
    "A shallow pit is filled with shattered blocks and silt. A toppled winch frame\n"
    "rests against the wall.\n";
  dest_dir = ([
    "north" : "/chapter/prologue/area/refuge/room280",
  ]);

  set_light(1);
}
