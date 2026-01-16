inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Avenue";
  long_desc =
    "The broad street narrows toward the western gate, its paving cracked.\n"
    "Shuttered archways watch over the quiet way.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1150", "east",
    "domain/original/area/anshelm/room1164", "north",
  });
}
