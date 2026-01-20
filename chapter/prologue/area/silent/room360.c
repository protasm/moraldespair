inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Cell";
  long_desc = "This small chamber is plain, its walls marked by soot and smoke. A slit window\nadmits a thin stripe of light.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room357", "west",
  });
}
