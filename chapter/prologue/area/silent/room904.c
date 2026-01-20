inherit "room/room";

void create() {
  ::create();

  short_desc = "Workshop Entry";
  long_desc = "A stone entry opens into a building of long worktables. The lintel is etched\nwith worn markings.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room905", "west",
    "chapter/prologue/area/silent/room906", "east",
    "chapter/prologue/area/silent/room390", "north",
  });

  set_light(1);
}
