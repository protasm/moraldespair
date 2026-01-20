inherit "room/room";

void create() {
  ::create();


  short_desc = "Guild/Shop Space for rent";
  long_desc = "Guild/Shop Space for rent.\n";
  dest_dir = ({
    "domain/original/area/island/room664", "north",
  });

  set_light(1);
}
