inherit "/room/room";

void create() {
  ::create();

  short_desc = "Upper Cell";
  long_desc =
    "This cramped room has a narrow slit for light and a floor of cracked stone.\n"
    "Water stains run down the corners.\n";
  dest_dir = ([
    "down" : "/chapter/prologue/area/refuge/room1158",
    "west" : "/chapter/prologue/area/refuge/room1160",
  ]);

  set_light(1);
}
