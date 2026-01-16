inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Riven Arch";
  long_desc = "A split stone arch leans over a scatter of fallen gate timbers and\n"
    "rusted iron. Deep grooves where a portcullis once slid are\n"
    "choked with mildew and windblown grit.\n";
  dest_dir = ({
    "domain/original/area/vesla/room168", "south",
    "domain/original/area/vesla/room753", "northeast",
  });
}
