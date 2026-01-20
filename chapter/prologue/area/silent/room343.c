inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Lawn";
  long_desc = "Broken statues stand amid tall grass, their faces worn away. Plinths sit\ncracked and empty where others fell.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room344", "south",
    "chapter/prologue/area/silent/room340", "north",
  });
}
