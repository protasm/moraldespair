inherit "room/room";

void create() {
  ::create();

  short_desc = "Black Gate";
  long_desc = "A tall gate of dark iron stands between two cracked pillars. The metal is\npitted and flecked with rust.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room384", "northwest",
    "chapter/prologue/area/silent/room387", "southeast",
  });

  set_light(1);
}
