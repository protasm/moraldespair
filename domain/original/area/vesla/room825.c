inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Landing";
  long_desc = "The upper landing is choked with dust, its rail warped and soft with rot. Closed doors lean inward, and a cracked mirror keeps a dim memory of bright rooms now gone to mildew.";
  dest_dir = ({
    "domain/original/area/vesla/room828", "south",
    "domain/original/area/vesla/room826", "west",
    "domain/original/area/vesla/room829", "up",
    "domain/original/area/vesla/room824", "down",
    "domain/original/area/vesla/room827", "north",
  });
}
