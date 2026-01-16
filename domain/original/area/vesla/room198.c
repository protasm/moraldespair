inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken Way";
  long_desc =
    "The old paving has slumped into a shallow trough, stones split and slick\n"
    "with moss. Dust and leaf mold blanket the centerline, and rusted iron bands\n"
    "lie half-buried where something once hung above the road.\n";
  dest_dir = ({
    "domain/original/area/vesla/room199", "south",
    "domain/original/area/vesla/room857", "east",
    "domain/original/area/vesla/room197", "north",
  });
}
