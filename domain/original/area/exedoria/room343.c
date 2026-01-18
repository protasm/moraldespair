inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Lawn";
  long_desc = "Broken statues stand amid tall grass, their faces worn away. Plinths sit\ncracked and empty where others fell.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room344", "south",
    "domain/original/area/exedoria/room340", "north",
  });
}
