inherit "room/room";

void create() {
  ::create();

  short_desc = "Riven Arch";
  long_desc = "A split stone arch leans over a scatter of fallen gate timbers and rusted iron. Deep grooves where a portcullis once slid are choked with mildew and windblown grit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room168", "south",
    "chapter/prologue/area/ruined/room753", "northeast",
  });

  set_light(1);
}
