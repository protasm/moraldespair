inherit "/room/room";

void create() {
  ::create();

  short_desc = "Gate Arch";
  long_desc =
    "The vaulting of the gatehouse is blackened with soot and age, and the\n"
    "portcullis is long gone. Light spills through gaps above where beams have\n"
    "fallen.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1143",
    "south" : "/chapter/prologue/area/refuge/room235",
    "north" : "/chapter/prologue/area/refuge/room237",
  ]);

  set_light(1);
}
