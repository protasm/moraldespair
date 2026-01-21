inherit "room/room";

void create() {
  ::create();

  short_desc = "Broken Road";
  long_desc = "Cracked paving gives way to patches of dirt and gravel. A few stones still\nhold the line of the old curb.\n";
  dest_dir = ([
    "east":"/chapter/prologue/area/silent/room305",
    "west":"/chapter/prologue/area/silent/room307",
  ]);

  set_light(1);
}
