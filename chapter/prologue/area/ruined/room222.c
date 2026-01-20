inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Taproom";
  long_desc = "Rot-softened beams sag over a long counter gone gray with dust and mildew. Benches lie broken in the hush, and a sour stain clings where drink once spilled. The hearth is cold, its iron hooks rusted and half-buried in grit.";
  dest_dir = ([
    "west":"/chapter/prologue/area/ruined/room223",
    "east":"/chapter/prologue/area/ruined/room221",
    "north":"/chapter/prologue/area/ruined/room119",
  ]);

  set_light(1);
}
