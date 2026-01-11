inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Threshold";
  long_desc = "The road angles west through a narrowed gap between leaning stonework. Chipped\n"
              + "blocks and pale grit mark a boundary that time has left without purpose.\n";
  dest_dir = ({
    "domain/original/area/vesla/room129", "west",
    "domain/original/area/vesla/room127", "east",
    "domain/original/area/vesla/room881", "north",
  });
}
