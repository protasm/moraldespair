inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Small Graves";
  long_desc = "Tiny stone markers jut from the earth in uneven lines. Many have tipped over\nor sunk into the soil.\n";
  dest_dir = ({
    "domain/original/area/exedoria/room371", "east",
  });
}
