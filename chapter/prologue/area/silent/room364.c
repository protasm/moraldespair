inherit "room/room";

void create() {
  ::create();

  short_desc = "Hall Bend";
  long_desc = "A gentle turn shifts the corridor toward colder air. The floor stones are\nchipped and uneven.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room365", "west",
    "chapter/prologue/area/silent/room362", "south",
  });

  set_light(1);
}
