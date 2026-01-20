inherit "room/room";

void create() {
  ::create();


  short_desc = "South Entryway";
  long_desc = "South Entryway.\n";
  dest_dir = ({
    "domain/original/area/island/room704", "north",
  });

  set_light(1);
}
