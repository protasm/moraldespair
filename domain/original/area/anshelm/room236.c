inherit "room/room";

void create() {
  ::create();

  short_desc = "Gate Arch";
  long_desc =
    "The vaulting of the gatehouse is blackened with soot and age, and the\n"
    "portcullis is long gone. Light spills through gaps above where beams have\n"
    "fallen.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room1143", "west",
    "domain/original/area/anshelm/room235", "south",
    "domain/original/area/anshelm/room237", "north",
  });

  set_light(1);
}
