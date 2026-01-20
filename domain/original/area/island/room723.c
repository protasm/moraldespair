inherit "room/room";

void create() {
  ::create();


  short_desc = "Crowded Thoroughfare";
  long_desc = "Crowded Thoroughfare.\n";
  dest_dir = ({
    "domain/original/area/island/room724", "south",
    "domain/original/area/island/room637", "north",
  });

  set_light(1);
}
