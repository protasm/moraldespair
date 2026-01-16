inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Ruined Works";
  long_desc = "An unfinished foundation lies open to the weather. Broken scaffolds lean where\nthey were left.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room899", "north",
  });
}
