inherit "room/room";

void create() {
  ::create();


  short_desc = "Silver Street";
  long_desc = 
    "The pale street-stones lead toward a wide, patterned plaza to the north.\n" +
    "Row upon row of glass-domed torches stand like sightless eyes, their\n" +
    "inner fires long since spent. To the east, the sharp, medicinal tang of\n" +
    "evaporated spirits lingers in the air. A low wall to the west overlooks\n" +
    "a choked canal where black, motionless water reflects only the gray sky.\n";
  dest_dir = ([
    "south" : "/domain/original/area/island/room612",
    "west" : "/domain/original/area/island/room675",
    "east" : "/domain/original/area/island/room676",
    "north" : "/domain/original/area/island/room614",
  ]);

  set_light(1);
}
