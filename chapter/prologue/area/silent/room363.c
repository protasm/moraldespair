inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Cell";
  long_desc = "A cramped room opens off the hall, empty of comforts. Scratches line the wall\nwhere wood once hung.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room362", "west",
  });

  set_light(1);
}
