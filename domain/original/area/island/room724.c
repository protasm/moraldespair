inherit "room/room";

void create() {
  ::create();


  short_desc = "Archway of Servitude";
  long_desc = "Archway of Servitude.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room725",
    "north" : "/domain/original/area/island/room723",
  ]);

  set_light(1);
}
