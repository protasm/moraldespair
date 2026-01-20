inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Pit";
  long_desc =
    "A shallow pit is filled with shattered blocks and silt. A toppled winch frame\n"
    "rests against the wall.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room280", "north",
  });

  set_light(1);
}
