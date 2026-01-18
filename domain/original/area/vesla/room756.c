inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Hollow Court";
  long_desc = "A wide paved court lies quiet, its cobbles sunken and furred with mildew. Old drain lines and a broken curb hint at orderly traffic long gone.";
  dest_dir = ({
    "domain/original/area/vesla/room755", "south",
    "domain/original/area/vesla/room757", "north",
  });
}
