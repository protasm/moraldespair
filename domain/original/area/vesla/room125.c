inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Junction";
  long_desc = "A wide junction opens where several streets once met. The\n"
              + "stones are worn smooth, and scattered rubble marks where\n"
              + "structures have slumped into the road.\n";
  dest_dir = ({
    "domain/original/area/vesla/room159", "south",
    "domain/original/area/vesla/room126", "west",
    "domain/original/area/vesla/room124", "east",
    "domain/original/area/vesla/room160", "north",
  });
}
