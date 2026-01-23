inherit "room/room";

void create() {
  ::create();

  short_desc = "Caved Chamber";
  long_desc =
    "A heavy collapse has split this chamber, exposing the sky. Slabs of stone lie\n"
    "piled in the center.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/anshelm/room240",
  ]);

  set_light(1);
}
