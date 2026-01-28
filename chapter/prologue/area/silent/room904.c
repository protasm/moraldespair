inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Workshop Entry";
  long_desc = "A stone entry opens into a building of long worktables. The lintel is etched\nwith worn markings.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room905",
    "east":"/chapter/prologue/area/silent/room906",
    "north":"/chapter/prologue/area/silent/room390",
  ]);

  set_light(1);
}
