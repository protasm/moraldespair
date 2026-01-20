inherit "room/room";

void create() {
  ::create();

  short_desc = "Side Room";
  long_desc =
    "A side chamber sits empty except for scattered rubble. The plaster has peeled\n"
    "away in long, curling strips.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1158", "up",
    "domain/original/area/anshelm/room1156", "down",
    "domain/original/area/anshelm/room1154", "west",
  });

  set_light(1);
}
