inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Street";
  long_desc =
    "A wide track of stone holds pooled rainwater. A shattered doorway arches into\n"
    "darkness.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room279", "east",
    "domain/original/area/anshelm/room277", "west",
  });

  set_light(1);
}
