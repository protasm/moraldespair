inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park's End";
  long_desc = "The walk widens before crumbling walls that once framed a corner of the city.\n"
              + "Loose stone and soil have spilled over the paving, and the air hangs still.\n";
  dest_dir = ({
    "domain/original/area/vesla/room880", "south",
    "domain/original/area/vesla/room127", "west",
    "domain/original/area/vesla/room125", "east",
    "domain/original/area/vesla/room879", "north",
  });
}
