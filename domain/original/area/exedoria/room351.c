inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Foyer";
  long_desc = "A plain foyer opens onto several doorways, each stripped of its doors. The\nceiling has darkened with age.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room352", "east",
    "domain/original/area/exedoria/room350", "south",
  });
}
