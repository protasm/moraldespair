inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "Old paving stones show through a blanket of dust and grit. Grass collects\nalong the edges in long seams.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room303", "west",
    "domain/original/area/exedoria/room300", "east",
    "domain/original/area/exedoria/room392", "south",
  });
}
