inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Iron Walk";
  long_desc =
    "Old iron rails bracket the street, many bent or missing. The roadway is\n"
    "scarred by shallow ruts.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room253", "south",
    "domain/original/area/anshelm/room255", "north",
  });
}
