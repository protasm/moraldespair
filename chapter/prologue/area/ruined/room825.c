inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Landing";
  long_desc = "The upper landing is choked with dust, its rail warped and soft with rot. Closed doors lean inward, and a cracked mirror keeps a dim memory of bright rooms now gone to mildew.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room828", "south",
    "chapter/prologue/area/ruined/room826", "west",
    "chapter/prologue/area/ruined/room829", "up",
    "chapter/prologue/area/ruined/room824", "down",
    "chapter/prologue/area/ruined/room827", "north",
  });
}
