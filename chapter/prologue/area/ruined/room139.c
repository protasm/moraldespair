inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Basalt Avenue";
  long_desc = "The avenue bends around sagging walls, the basalt setts uneven and underfoot. Moss clings in the seams, and broken steps lead into silent, collapsed doorways.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room140", "south",
    "chapter/prologue/area/ruined/room853", "west",
    "chapter/prologue/area/ruined/room854", "east",
    "chapter/prologue/area/ruined/room138", "north",
  });
}
