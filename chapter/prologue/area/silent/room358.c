inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Hall Bend";
  long_desc = "The hallway bends around a thick pillar, hiding what lies beyond. Dust gathers\nin the corner where the light fades.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room359",
    "north":"/chapter/prologue/area/silent/room357",
  ]);

  set_light(1);
}
