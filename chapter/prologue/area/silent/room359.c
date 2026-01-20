inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Cell";
  long_desc = "A narrow cell holds a bare cot frame and a low shelf. The stone is cold and\ndamp.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room358", "east",
  });
}
