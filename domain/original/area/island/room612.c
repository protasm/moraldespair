inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Silver Street (test stub)";
  long_desc = "Test stub for room612. Minimal reset to debug update errors.\n";
  dest_dir = ({
    "domain/original/area/island/room613", "north",
    "domain/original/area/island/room674", "east",
    "domain/original/area/island/room611", "south",
    "domain/original/area/island/room642", "west"
  });
}
