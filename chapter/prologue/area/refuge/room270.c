inherit "/room/room";

void create() {
  ::create();

  short_desc = "Long Street";
  long_desc =
    "The road runs straight between crumbling barracks. Wind has pushed leaves into\n"
    "slow drifts.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room271",
    "east" : "/chapter/prologue/area/refuge/room269",
    "south" : "/chapter/prologue/area/refuge/room1199",
  ]);

  set_light(1);
}
