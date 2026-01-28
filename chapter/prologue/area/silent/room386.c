inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Black Gate";
  long_desc = "A tall gate of dark iron stands between two cracked pillars. The metal is\npitted and flecked with rust.\n";
  dest_dir = ([
    "northwest":"/chapter/prologue/area/silent/room384",
    "southeast":"/chapter/prologue/area/silent/room387",
  ]);

  set_light(1);
}
