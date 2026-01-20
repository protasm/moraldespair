inherit "room/room";

void create() {
  ::create();


  short_desc = "Archway of Servitude";
  long_desc = "Archway of Servitude.\n";
  dest_dir = ({
    "domain/original/area/island/room725", "south",
    "domain/original/area/island/room723", "north",
  });

  set_light(1);
}
