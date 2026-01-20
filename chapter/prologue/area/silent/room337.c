inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Street";
  long_desc = "Cracked paving leads past shuttered houses with sagging roofs. Grass grows in\na thin line along the middle.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room336", "west",
    "chapter/prologue/area/silent/room338", "east",
    "chapter/prologue/area/silent/room603", "south",
  });
}
