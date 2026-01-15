inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "Basalt Avenue runs between low facades, their lintels split and worn with age.\n"
              + "Thin grass pushes through the cracks, and loose stones have slid into the\n"
              + "road.\n";
  dest_dir = ({
    "domain/original/area/vesla/room142", "south",
    "domain/original/area/vesla/room140", "north",
  });
}
