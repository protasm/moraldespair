inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Silent Row";
  long_desc =
    "Paving stones are missing in patches, leaving uneven earth. A stretch of\n"
    "wrought iron railing clings to one wall, bent inward.\n";
  dest_dir = ({
    "domain/original/area/anshelm/room242", "south",
    "domain/original/area/anshelm/room244", "north",
  });
}
