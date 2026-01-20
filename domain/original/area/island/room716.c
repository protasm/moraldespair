inherit "room/room";

void create() {
  ::create();


  short_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible";
  long_desc = "You feel a STRONG urge to read the Sanctuary board... You are responsible.\n";
  dest_dir = ({
    "domain/original/area/island/room713", "south",
  });

  set_light(1);
}
