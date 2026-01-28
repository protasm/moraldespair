inherit "/room/room";

void create() {
  ::create();

  short_desc = "Stone Avenue";
  long_desc =
    "A wide street runs between elegant facades, their arches chipped and open.\n"
    "Wrought iron balconies sag above the broken paving.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/refuge/room1157",
    "east" : "/chapter/prologue/area/refuge/room1147",
    "south" : "/chapter/prologue/area/refuge/room1168",
  ]);

  set_light(1);
}
