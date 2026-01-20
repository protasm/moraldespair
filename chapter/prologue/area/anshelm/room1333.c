inherit "room/room";

void create() {
  ::create();

  short_desc = "North Statuary";
  long_desc =
    "The remains of carved figures crowd the north wall in silent rows. Lichen\n"
    "spreads across their fractured bases.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room1330", "south",
  });

  set_light(1);
}
