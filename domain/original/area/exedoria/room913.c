inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Servant Wing";
  long_desc = "Hanging vines trail through a low entry into a row of small rooms. The floor\nis littered with leaves and dust.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room912", "west",
  });
}
