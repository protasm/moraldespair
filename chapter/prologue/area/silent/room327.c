inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Narrow Alley";
  long_desc = "This passage is hemmed by close walls and a broken gutter. Thin weeds reach up\nfrom packed dirt.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room326", "south",
    "chapter/prologue/area/silent/room328", "north",
  });
}
