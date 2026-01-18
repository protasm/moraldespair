inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Road Start";
  long_desc = "A broader road begins near a low wall of fallen stone. The surface is cracked\nbut still passable.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room385", "west",
    "domain/original/area/exedoria/room386", "southeast",
    "domain/original/area/exedoria/room383", "north",
  });
}
