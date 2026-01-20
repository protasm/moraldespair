inherit "room/room";

void create() {
  ::create();


  short_desc = "Island Historical Society";
  long_desc = "Island Historical Society.\n";
  dest_dir = ({
    "domain/original/area/island/room664", "south",
    "domain/original/area/island/room669", "north",
  });

  set_light(1);
}
