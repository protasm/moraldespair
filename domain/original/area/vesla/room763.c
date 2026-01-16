inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Upper Steps";
  long_desc = "The upper steps rise into a roofless shaft where rain darkens the\n"
    "stone. Loose grit and rust flakes collect along the wall where a\n"
    "rail once ran.\n";
  dest_dir = ({
    "domain/original/area/vesla/room764", "southwest",
    "domain/original/area/vesla/room761", "down",
  });
}
