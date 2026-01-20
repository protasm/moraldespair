inherit "room/room";

void create() {
  ::create();


  short_desc = "House of Balin";
  long_desc = "House of Balin.\n";
  dest_dir = ({
    "domain/original/area/island/room712", "west",
    "domain/original/area/island/room654", "south",
  });

  set_light(1);
}
