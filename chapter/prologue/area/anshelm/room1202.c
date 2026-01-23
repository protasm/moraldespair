inherit "room/room";

void create() {
  ::create();

  short_desc = "Abandoned Works";
  long_desc =
    "Loose courses of stone mark the outline of a forgotten build. Wind has piled\n"
    "grit against a fallen beam.\n";
  dest_dir = ([
    "southeast" : "/chapter/prologue/area/anshelm/room273",
  ]);

  set_light(1);
}
