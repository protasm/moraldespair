inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Upper Room";
  long_desc =
    "A small chamber holds a cracked basin and a warped doorway. The walls are\n"
    "stained by long-dry smoke.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1142", "west",
  });
}
