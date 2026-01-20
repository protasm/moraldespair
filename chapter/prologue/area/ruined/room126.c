inherit "room/room";

void create() {
  ::create();

  short_desc = "Park's End";
  long_desc = "The walk widens before crumbling walls that once framed a corner of the city. Loose stone and soil have spilled over the paving, and the air hangs still.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room880", "south",
    "chapter/prologue/area/ruined/room127", "west",
    "chapter/prologue/area/ruined/room125", "east",
    "chapter/prologue/area/ruined/room879", "north",
  });

  set_light(1);
}
