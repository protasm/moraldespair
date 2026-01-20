inherit "room/room";

void create() {
  ::create();

  short_desc = "Hall Bend";
  long_desc = "The hallway bends around a thick pillar, hiding what lies beyond. Dust gathers\nin the corner where the light fades.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room359", "west",
    "chapter/prologue/area/silent/room357", "north",
  });

  set_light(1);
}
