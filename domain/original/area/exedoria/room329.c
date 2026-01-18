inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Alley Mouth";
  long_desc = "A narrow opening splits the row of buildings, leading into shadow. The lintel\nabove is cracked and sagging.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room328", "south",
    "domain/original/area/exedoria/room303", "north",
  });
}
