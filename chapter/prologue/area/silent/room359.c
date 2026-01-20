inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "A narrow cell holds a bare cot frame and a low shelf. The stone is cold and\ndamp.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room358", "east",
  });

  set_light(1);
}
