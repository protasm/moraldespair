inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Home";
  long_desc = "Dwarven Home.\n";
  dest_dir = ({
    "domain/original/area/island/room648", "west",
  });

  set_light(1);
}
