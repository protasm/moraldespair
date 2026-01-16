inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Stone Cell";
  long_desc = "A cramped room opens off the hall, empty of comforts. Scratches line the wall\nwhere wood once hung.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room362", "west",
  });
}
