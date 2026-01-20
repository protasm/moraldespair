inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Alley Mouth";
  long_desc = "A narrow opening splits the row of buildings, leading into shadow. The lintel\nabove is cracked and sagging.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room328", "south",
    "chapter/prologue/area/silent/room303", "north",
  });
}
