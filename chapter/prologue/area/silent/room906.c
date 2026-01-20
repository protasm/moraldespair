inherit "room/room";

void create() {
  ::create();

  short_desc = "Lecture Hall";
  long_desc = "Stepped benches rise in a semicircle, all coated with dust. A cracked slate\nstands at the front.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room904", "west",
  });

  set_light(1);
}
