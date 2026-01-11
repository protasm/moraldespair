inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Choir";
  long_desc = "A narrow gallery runs above the main hall, its railings split and softened by\n"
              + "rot. Torn cloth once bright hangs in strips, and the air is still but for the\n"
              + "dry rattle of loose tiles.\n";
  dest_dir = ({
    "domain/original/area/vesla/room405", "north",
  });
}
