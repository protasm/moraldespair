inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Check";
  long_desc = "A narrow archway divides the street, flanked by low guard niches. The stone\nbears faint carvings worn flat by time.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room314", "north",
  });
}
