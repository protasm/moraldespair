inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Park Crossroads";
  long_desc = "The crossing is choked with gravel and dead leaves where a broad street meets\n"
              + "a narrower lane. Fallen posts and a tilted sign hold a silence settled over\n"
              + "long neglect.\n";
  dest_dir = ({
    "domain/original/area/vesla/room233", "south",
    "domain/original/area/vesla/room117", "west",
    "domain/original/area/vesla/room115", "east",
    "domain/original/area/vesla/room172", "north",
  });
}
