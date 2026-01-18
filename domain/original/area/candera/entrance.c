inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken City";
  long_desc = "Once a city, now swallowed by the desert.";
  dest_dir = ({
    "domain/original/area/roadway/room1", "east",
    "domain/original/area/candera/room1", "city",
  });

  add_exit_alias("c", "city");
}
