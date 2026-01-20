inherit "room/room";

void create() {
  ::create();

  short_desc = "Cracked Crossing";
  long_desc = "Two worn ways meet in a sagging cross, their seams packed with damp grit and tiny weeds. The center stones are polished hollow by long-forgotten traffic, with rust flakes gathered in the low joints.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room201", "west",
    "chapter/prologue/area/ruined/room199", "north",
  });

  set_light(1);
}
