inherit "room/room";

void create() {
  ::create();


  short_desc = "Dwarven Hut";
  long_desc = "Dwarven Hut.\n";
  dest_dir = ({
    "domain/original/area/island/room644", "south",
  });

  set_light(1);
}
