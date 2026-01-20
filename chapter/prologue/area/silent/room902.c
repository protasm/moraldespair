inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Works";
  long_desc = "An unfinished foundation lies open to the weather. Broken scaffolds lean where\nthey were left.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room899", "north",
  });

  set_light(1);
}
