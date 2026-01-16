inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "North Statuary";
  long_desc =
    "The remains of carved figures crowd the north wall in silent rows. Lichen\n"
    "spreads across their fractured bases.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1330", "south",
  });
}
