inherit "room/room";

void create() {
  ::create();


  short_desc = "Council Chamber";
  long_desc = "Council Chamber.\n";
  dest_dir = ({
    "domain/original/area/island/room681", "east",
    "domain/original/area/island/room683", "west",
  });

  set_light(1);
}
