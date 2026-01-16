inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Cracked Circle";
  long_desc = "A low ring of stone marks a circle at the center of the road. Whatever stood\nhere is gone, leaving only shattered plinths.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room299", "south",
    "domain/original/area/exedoria/room289", "west",
    "domain/original/area/exedoria/room291", "east",
    "domain/original/area/exedoria/room369", "north",
  });
}
