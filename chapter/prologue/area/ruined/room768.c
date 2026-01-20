inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Gray Court";
  long_desc = "Gray dust coats the paving, and fragments of plaster lie in soft ridges. A broad, straight run of stones implies an old processional path through the ward.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room766", "southwest",
    "chapter/prologue/area/ruined/room767", "west",
    "chapter/prologue/area/ruined/room769", "east",
    "chapter/prologue/area/ruined/room765", "south",
  });
}
