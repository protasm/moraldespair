inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Empty Taproom";
  long_desc = "Rot-softened beams sag over a long counter gone gray with dust and mildew. Benches lie broken in the hush, and a sour stain clings where drink once spilled. The hearth is cold, its iron hooks rusted and half-buried in grit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room223", "west",
    "chapter/prologue/area/ruined/room221", "east",
    "chapter/prologue/area/ruined/room119", "north",
  });
}
