inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "High Passage";
  long_desc =
    "This passage runs along the upper wall, with gaps where the parapet has\n"
    "crumbled. Wind slips through the open stonework.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1137",
    "east" : "/chapter/prologue/area/refuge/room1144",
    "up" : "/chapter/prologue/area/refuge/room1139",
  ]);

  set_light(1);
}
