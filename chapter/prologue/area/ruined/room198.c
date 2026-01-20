inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken Way";
  long_desc = "The old paving has slumped into a shallow trough, stones split and slick with moss. Dust and leaf mold blanket the centerline, and rusted iron bands lie half-buried where something once hung above the road.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room199", "south",
    "chapter/prologue/area/ruined/room857", "east",
    "chapter/prologue/area/ruined/room197", "north",
  });
}
