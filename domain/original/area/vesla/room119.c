inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shattered Walk";
  long_desc = "The covered path is broken here, its ribs split and scattered\n"
              + "across the paving. Wind drifts through the gaps, stirring\n"
              + "leaves that have gathered in the hollows.\n";
  dest_dir = ({
    "domain/original/area/vesla/room222", "south",
    "domain/original/area/vesla/room120", "west",
    "domain/original/area/vesla/room118", "east",
    "domain/original/area/vesla/room230", "north",
  });
}
