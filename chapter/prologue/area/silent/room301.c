inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shuttered Shop";
  long_desc = "A narrow storefront sits silent, its signboard fallen into the street. The\ninterior is stripped and open to weather.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room300", "north",
  });
}
