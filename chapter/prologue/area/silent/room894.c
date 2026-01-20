inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dorm Foyer";
  long_desc = "A plain foyer opens into several small chambers. Dust lies thick where beds\nonce stood.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room528", "west",
    "chapter/prologue/area/silent/room895", "south",
    "chapter/prologue/area/silent/room903", "north",
  });
}
