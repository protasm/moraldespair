inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Dark Pit";
  long_desc = "A round shaft drops into darkness, its rim lined with broken stone. Cold air\npools at the mouth and carries the scent of damp earth.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room316", "north",
  });
}
