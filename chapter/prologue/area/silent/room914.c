inherit "//chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "High Room";
  long_desc = "A small room opens onto a broken balcony above the ground. The ceiling is\nstained with rain.\n";
  dest_dir = ([
    "down":"/chapter/prologue/area/silent/room909",
  ]);

  set_light(1);
}
