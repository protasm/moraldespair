inherit "room/room";

void create() {
  ::create();

  short_desc = "West Avenue";
  long_desc =
    "The broad street narrows toward the western gate, its paving cracked.\n"
    "Shuttered archways watch over the quiet way.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room1150",
    "north" : "/chapter/prologue/area/anshelm/room1164",
  ]);

  set_light(1);
}
