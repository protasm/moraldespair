inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Choir";
  long_desc = "A narrow gallery runs above the main hall, its railings split and softened by rot. Torn cloth once bright hangs in strips, and the air is still but for the dry rattle of loose tiles.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room405", "north",
  });
}
