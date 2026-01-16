inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Street";
  long_desc = "Cracked paving leads past shuttered houses with sagging roofs. Grass grows in\na thin line along the middle.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room336", "west",
    "domain/original/area/exedoria/room338", "east",
    "domain/original/area/exedoria/room603", "south",
  });
}
