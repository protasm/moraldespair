inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Foyer";
  long_desc = "A wide entry hall stands open to the street, swept by dust. Torn curtains hang\nfrom a balcony that no longer shelters the floor.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room307", "southeast",
    "chapter/prologue/area/silent/room332", "west",
  });

  set_light(1);
}
