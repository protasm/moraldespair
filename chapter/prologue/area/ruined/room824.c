inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Shuttered House";
  long_desc = "Heavy curtains hang in strips, their fabric stiff with dust and mildew. Low couches have collapsed into rot, and a faint sweetness lingers where perfume once clung to the air.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room158", "east",
    "chapter/prologue/area/ruined/room825", "up",
  });
}
