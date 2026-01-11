inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Bare Chamber";
  long_desc = "A narrow bedframe sags against the wall, its straw long moldered into dust. A\n"
              + "cracked chest sits open, and a single practice rail leans nearby, dulled by\n"
              + "mildew and time.\n";
  dest_dir = ({
    "domain/original/area/vesla/room399", "down",
  });
}
