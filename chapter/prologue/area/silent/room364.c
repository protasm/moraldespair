inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Hall Bend";
  long_desc = "A gentle turn shifts the corridor toward colder air. The floor stones are\nchipped and uneven.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room365",
    "south":"/chapter/prologue/area/silent/room362",
  ]);

  set_light(1);
}
