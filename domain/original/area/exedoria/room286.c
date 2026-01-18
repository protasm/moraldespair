inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Gate";
  long_desc = "A fractured gatehouse leans over the road, its doors long gone. Wind moves\nthrough the empty arch where iron once hung.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room287", "east",
    "domain/original/area/exedoria/entrance", "exit",
  });

  add_exit_alias("x", "exit");
}
