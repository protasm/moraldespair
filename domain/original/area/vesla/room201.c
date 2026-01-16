inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Way";
  long_desc =
    "A narrow run of stone drifts westward, the joints packed with gray silt and\n"
    "moss. A bent iron frame clings to one wall, as if a bell or lantern once\n"
    "marked the passage.\n";
  dest_dir = ({
    "domain/original/area/vesla/room843", "south",
    "domain/original/area/vesla/room202", "west",
    "domain/original/area/vesla/room200", "east",
  });
}
