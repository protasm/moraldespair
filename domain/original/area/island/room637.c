inherit "room/room";

void create() {
  ::create();


  short_desc = "West End of Balin Road";
  long_desc = "West End of Balin Road.\n";
  dest_dir = ({
    "domain/original/area/island/room638", "west",
    "domain/original/area/island/room720", "northeast",
    "domain/original/area/island/room636", "east",
    "domain/original/area/island/room723", "south",
  });

  set_light(1);
}
