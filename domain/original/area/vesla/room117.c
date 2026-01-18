inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Grit-Streaked Crossing";
  long_desc = "Weathered stones mark the meeting of two old streets, their lines softened by drifted grit. A broken post leans over the junction, and no track has passed in generations.";
  dest_dir = ({
    "domain/original/area/vesla/room220", "south",
    "domain/original/area/vesla/room118", "west",
    "domain/original/area/vesla/room116", "east",
    "domain/original/area/vesla/room226", "north",
  });
}
