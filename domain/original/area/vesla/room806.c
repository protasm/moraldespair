inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Shear Room";
  long_desc = "A narrow room holds a cracked stone basin and a warped chair frame.\n"
    "Rust flakes and dust cover the floor where tools once hung in neat\n"
    "rows.\n";
  dest_dir = ({
    "domain/original/area/vesla/room800", "south",
  });
}
