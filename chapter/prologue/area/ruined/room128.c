inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Westroad Threshold";
  long_desc = "The road angles west through a narrowed gap between leaning stonework. Chipped blocks and pale grit mark a boundary that time has left without purpose.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room129", "west",
    "chapter/prologue/area/ruined/room127", "east",
  });
}
