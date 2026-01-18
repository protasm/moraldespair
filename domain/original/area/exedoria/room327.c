inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Alley";
  long_desc = "This passage is hemmed by close walls and a broken gutter. Thin weeds reach up\nfrom packed dirt.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room326", "south",
    "domain/original/area/exedoria/room328", "north",
  });
}
