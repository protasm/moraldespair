inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Railed Gate";
  long_desc = "A short railing borders a narrow entry in the wall. The iron bars are bent and\nmottled with rust.\n";
  dest_dir = ([
    "south":"/chapter/prologue/area/silent/room336",
  ]);

  set_light(1);
}
