inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rutted Street";
  long_desc = "The street lies uneven, its stones tilted and split. Vines trail across the\nroad in slow, careless loops.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room294", "east",
    "chapter/prologue/area/silent/room292", "west",
  });
}
