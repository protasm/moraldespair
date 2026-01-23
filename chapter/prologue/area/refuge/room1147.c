inherit "room/room";

void create() {
  ::create();

  short_desc = "Promenade";
  long_desc =
    "A broad walk runs along the inner wall, its stone railing cracked and low.\n"
    "Ornate ironwork curves still cling to a few posts.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1150",
    "east" : "/chapter/prologue/area/refuge/room414",
    "north" : "/chapter/prologue/area/refuge/room1169",
  ]);

  set_light(1);
}
