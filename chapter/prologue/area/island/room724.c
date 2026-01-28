inherit "//chapter/prologue/std/room";

void create() {
  ::create();


  short_desc = "Archway of Servitude";
  long_desc = "Archway of Servitude.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/island/room725",
    "north" : "/chapter/prologue/area/island/room723",
  ]);

  set_light(1);
}
