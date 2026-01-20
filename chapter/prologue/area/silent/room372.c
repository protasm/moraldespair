inherit "room/room";

void create() {
  ::create();

  short_desc = "Small Graves";
  long_desc = "Tiny stone markers jut from the earth in uneven lines. Many have tipped over\nor sunk into the soil.\n";
  dest_dir = ({
    "chapter/prologue/area/silent/room371", "east",
  });

  set_light(1);
}
