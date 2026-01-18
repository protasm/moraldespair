inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Middle Steps";
  long_desc = "The stairwell turns here, crowded by damp stone and a fractured landing. Dust cakes the treads, and a broken sconce hints at night watches that ended long ago.";
  dest_dir = ({
    "domain/original/area/vesla/room762", "southwest",
    "domain/original/area/vesla/room760", "down",
    "domain/original/area/vesla/room763", "up",
  });
}
