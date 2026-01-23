inherit "room/room";

void create() {
  ::create();

  short_desc = "Broad Street";
  long_desc =
    "A wide street runs beneath faded facades with ornate iron balconies. Many of\n"
    "the balconies have collapsed, leaving jagged anchors.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room239",
    "east" : "/chapter/prologue/area/refuge/room1186",
    "north" : "/chapter/prologue/area/refuge/room1191",
  ]);

  set_light(1);
}
