inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Sunken Walk";
  long_desc = "The walkway dips into a shallow trough where stones have\n"
              + "settled unevenly. A thin film of moss trails along the\n"
              + "seams, and the air sits heavy with damp.\n";
  dest_dir = ({
    "domain/original/area/vesla/room224", "south",
    "domain/original/area/vesla/room122", "west",
    "domain/original/area/vesla/room120", "east",
    "domain/original/area/vesla/room425", "north",
  });
}
