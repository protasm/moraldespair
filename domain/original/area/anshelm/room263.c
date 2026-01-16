inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "West Lane";
  long_desc =
    "The street ends at a tumbled wall where stones have slid down. A narrow alley\n"
    "slips away beside the ruin.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room262", "east",
  });
}
