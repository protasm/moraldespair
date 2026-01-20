inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Rooms";
  long_desc = "Two small rooms sit open to the street, silent, dusty, and ruined. A cold hearth and broken bedframe are soft with mildew and rot, hinting at cramped living left behind.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room139", "east",
  });

  set_light(1);
}
