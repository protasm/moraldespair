inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dorm Foyer";
  long_desc = "A plain foyer opens into several small chambers. Dust lies thick where beds\nonce stood.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room528", "west",
    "domain/original/area/exedoria/room895", "south",
    "domain/original/area/exedoria/room903", "north",
  });
}
