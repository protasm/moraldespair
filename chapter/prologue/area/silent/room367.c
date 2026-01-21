inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Tavern";
  long_desc = "A once-lively tavern sits dim behind broken windows. A sagging stage and\nsplintered stools fill the corners.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room288",
  ]);

  set_light(1);
}
