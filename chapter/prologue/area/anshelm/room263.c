inherit "room/room";

void create() {
  ::create();

  short_desc = "West Lane";
  long_desc =
    "The street ends at a tumbled wall where stones have slid down. A narrow alley\n"
    "slips away beside the ruin.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/anshelm/room262",
  ]);

  set_light(1);
}
