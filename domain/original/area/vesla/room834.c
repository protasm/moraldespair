inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Office";
  long_desc = "A heavy chair sits askew behind a broad desk, both softened by rot and damp. Dust mounds around a broken seal press, and mildew climbs the cracked plaster.";
  dest_dir = ({
    "domain/original/area/vesla/room833", "east",
  });
}
