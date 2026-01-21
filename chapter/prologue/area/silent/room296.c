inherit "room/room";

void create() {
  ::create();

  short_desc = "Rutted Street";
  long_desc = "Dry mud fills the depressions in the street. Thistles and briars knot along\nthe broken verge.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room297",
    "west":"/chapter/prologue/area/silent/room295",
  ]);

  set_light(1);
}
