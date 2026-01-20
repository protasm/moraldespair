inherit "room/room";

void create() {
  ::create();


  short_desc = "Trophy Room";
  long_desc = "Trophy Room.\n";
  dest_dir = ({
    "domain/original/area/island/room682", "east",
  });

  set_light(1);
}
