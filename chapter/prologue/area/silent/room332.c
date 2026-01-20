inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dusty Taproom";
  long_desc = "A low room of tables and a cracked bar lies silent. Dull glass and dry spills\nstain the floor.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room331", "east",
  });
}
