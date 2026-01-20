inherit "room/room";

void create() {
  ::create();

  short_desc = "Park's End";
  long_desc = "The walk widens before crumbling walls that once framed a corner of the city. Loose stone and soil have spilled over the paving, and the air hangs still.";
  dest_dir = ([
    "south":"/chapter/prologue/area/ruined/room880",
    "west":"/chapter/prologue/area/ruined/room127",
    "east":"/chapter/prologue/area/ruined/room125",
    "north":"/chapter/prologue/area/ruined/room879",
  ]);

  set_light(1);
}
