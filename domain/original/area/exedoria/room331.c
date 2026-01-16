inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Foyer";
  long_desc = "A wide entry hall stands open to the street, swept by dust. Torn curtains hang\nfrom a balcony that no longer shelters the floor.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room307", "southeast",
    "domain/original/area/exedoria/room332", "west",
  });
}
