inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Pale Road";
  long_desc =
    "The paving here is pale and smoothed by time. A cracked column base lies\n"
    "beside a doorway.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room251", "south",
    "domain/original/area/anshelm/room253", "north",
  });
}
