inherit "room/room";

void create() {
  ::create();

  short_desc = "Empty Street";
  long_desc =
    "A wide track of stone holds pooled rainwater. A shattered doorway arches into\n"
    "darkness.\n";
  dest_dir = ([
    "east" : "/chapter/prologue/area/refuge/room279",
    "west" : "/chapter/prologue/area/refuge/room277",
  ]);

  set_light(1);
}
