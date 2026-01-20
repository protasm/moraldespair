inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruin Passage";
  long_desc =
    "A narrow passage runs through broken walls, half open to the air. Rubble\n"
    "mounds force the path to one side.\n";
  dest_dir = ({
    "chapter/prologue/area/anshelm/room251", "west",
  });

  set_light(1);
}
