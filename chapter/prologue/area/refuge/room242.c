inherit "room/room";

void create() {
  ::create();

  short_desc = "Inner Gate";
  long_desc =
    "A second gate rises ahead, its guardwalk broken and open to the sky. Weed-\n"
    "choked steps lead through the arch.\n";
  dest_dir = ([
    "south" : "/chapter/prologue/area/refuge/room241",
    "north" : "/chapter/prologue/area/refuge/room243",
  ]);

  set_light(1);
}
