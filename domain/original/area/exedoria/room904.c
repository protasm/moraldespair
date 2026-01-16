inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Workshop Entry";
  long_desc = "A stone entry opens into a building of long worktables. The lintel is etched\nwith worn markings.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room905", "west",
    "domain/original/area/exedoria/room906", "east",
    "domain/original/area/exedoria/room390", "north",
  });
}
