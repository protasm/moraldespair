inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Paneled Hall";
  long_desc = "Wood panels line the hall, warped and split by damp. Their varnish has dulled\nto a gray sheen.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room351",
    "north":"/chapter/prologue/area/silent/room353",
  ]);

  set_light(1);
}
