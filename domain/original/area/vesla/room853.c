inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Quiet Rooms";
  long_desc = "Two small rooms sit open to the street, silent, dusty, and ruined. A cold hearth and broken bedframe are soft with mildew and rot, hinting at cramped living left behind.";
  dest_dir = ({
    "domain/original/area/vesla/room139", "east",
  });
}
