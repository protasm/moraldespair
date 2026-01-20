inherit "room/room";

void create() {
  ::create();

  short_desc = "High Room";
  long_desc = "A small room opens onto a broken balcony above the ground. The ceiling is\nstained with rain.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room909", "down",
  });

  set_light(1);
}
