inherit "room/room";

void create() {
  ::create();

  short_desc = "Dry Tap";
  long_desc = "A cracked counter and dry cask stand in silence, the space dim and neglected. Dust, mildew, and rot cling to the shelves, hinting at a taproom left to fade.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room850",
  ]);

  set_light(1);
}
