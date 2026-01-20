inherit "room/room";

void create() {
  ::create();

  short_desc = "West Avenue";
  long_desc =
    "The broad street narrows toward the western gate, its paving cracked.\n"
    "Shuttered archways watch over the quiet way.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1150", "east",
    "chapter/prologue/area/anshelm/room1164", "north",
  });

  set_light(1);
}
