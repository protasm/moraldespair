inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Pit";
  long_desc =
    "A shallow pit is filled with shattered blocks and silt. A toppled winch frame\n"
    "rests against the wall.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room280", "north",
  });
}
