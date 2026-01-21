inherit "room/room";

void create() {
  ::create();

  short_desc = "Lane End";
  long_desc = "The lane ends at a collapsed wall and a heap of stone. The path beyond has\nfaded into dirt.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room354",
    "south":"/chapter/prologue/area/silent/room313",
    "north":"/chapter/prologue/area/silent/room311",
  ]);

  set_light(1);
}
