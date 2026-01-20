inherit "room/room";

void create() {
  ::create();

  short_desc = "High Passage";
  long_desc =
    "This passage runs along the upper wall, with gaps where the parapet has\n"
    "crumbled. Wind slips through the open stonework.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1137", "down",
    "domain/original/area/anshelm/room1144", "east",
    "domain/original/area/anshelm/room1139", "up",
  });

  set_light(1);
}
