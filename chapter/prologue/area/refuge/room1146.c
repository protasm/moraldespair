inherit "room/room";

void create() {
  ::create();

  short_desc = "Upper Passage";
  long_desc =
    "A narrow passage runs along the inner wall, lit by a broken slit. Fine grit\n"
    "lies under fallen plaster.\n";
  dest_dir = ([
    "up" : "/chapter/prologue/area/refuge/room1151",
    "west" : "/chapter/prologue/area/refuge/room1145",
  ]);

  set_light(1);
}
