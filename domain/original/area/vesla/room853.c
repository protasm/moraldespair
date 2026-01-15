inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Quiet Rooms";
  long_desc = "Two small rooms sit open to the street, silent, dusty, and ruined. A cold\n"
              + "hearth and broken bedframe are soft with mildew and rot, hinting at cramped\n"
              + "living left behind.\n";
  dest_dir = ({
    "domain/original/area/vesla/room139", "east",
  });
}
