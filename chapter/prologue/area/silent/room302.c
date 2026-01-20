inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Road";
  long_desc = "Old paving stones show through a blanket of dust and grit. Grass collects\nalong the edges in long seams.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room303", "west",
    "chapter/prologue/area/silent/room300", "east",
    "chapter/prologue/area/silent/room392", "south",
  });
}
