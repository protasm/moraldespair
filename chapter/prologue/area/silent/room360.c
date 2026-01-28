inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "This small chamber is plain, its walls marked by soot and smoke. A slit window\nadmits a thin stripe of light.\n";
  dest_dir = ([
    "west":"/chapter/prologue/area/silent/room357",
  ]);

  set_light(1);
}
