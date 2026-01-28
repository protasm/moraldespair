inherit "/room/room";

void create() {
  ::create();

  short_desc = "Empty Lounge";
  long_desc =
    "Wide windows face the street, their frames hanging loose and bare. Bits of\n"
    "colored plaster remain on the walls, muted by age.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room236",
    "west" : "/chapter/prologue/area/refuge/room1204",
  ]);

  set_light(1);
}
