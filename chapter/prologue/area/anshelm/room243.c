inherit "room/room";

void create() {
  ::create();

  short_desc = "Silent Row";
  long_desc =
    "Paving stones are missing in patches, leaving uneven earth. A stretch of\n"
    "wrought iron railing clings to one wall, bent inward.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room242", "south",
    "chapter/prologue/area/anshelm/room244", "north",
  });

  set_light(1);
}
