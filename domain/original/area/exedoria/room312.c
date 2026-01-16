inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Lane End";
  long_desc = "The lane ends at a collapsed wall and a heap of stone. The path beyond has\nfaded into dirt.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room354", "west",
    "domain/original/area/exedoria/room313", "south",
    "domain/original/area/exedoria/room311", "north",
  });
}
