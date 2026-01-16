inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Study Hall";
  long_desc = "Rows of benches face a high dais in a broad hall. The floor is scuffed by\nlong-quiet feet.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room899", "west",
    "domain/original/area/exedoria/room901", "north",
  });
}
