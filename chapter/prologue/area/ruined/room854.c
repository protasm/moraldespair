inherit "room/room";

void create() {
  ::create();

  short_desc = "Scented Stall";
  long_desc = "Rusted tins and cracked jars sit on sagging shelves, silent beneath dust and mildew. A faint, stale sweetness clings to the rot, hinting at spice trade in quiet neglect.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room139",
  ]);

  set_light(1);
}
