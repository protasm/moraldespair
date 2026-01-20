inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Shack";
  long_desc = "Dwarven Shack.\n";
  dest_dir = ({
    "domain/original/area/island/room648", "north",
  });

  set_light(1);
}
