inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "City of the Dead";
  long_desc = "A city overtaken by the dead.";
  dest_dir = ({
    "domain/original/area/roadway/room71", "north",
    "domain/original/area/indel/room1401", "city",
  });

  add_exit_alias("c", "city");
}
