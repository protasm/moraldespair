inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Yard";
  long_desc = "Practice posts lean at odd angles, their tops splintered and gray with rot. Racks of rusted gear line the walls, and dust has buried the scuffed floor where drills once rang.";
  dest_dir = ({
    "domain/original/area/vesla/room156", "west",
  });
}
