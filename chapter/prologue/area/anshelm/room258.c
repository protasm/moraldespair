inherit "room/room";

void create() {
  ::create();

  short_desc = "Market Crossing";
  long_desc =
    "Two streets intersect around a scatter of broken paving. A split wagon wheel\n"
    "rests in the gutter.\n";
  dest_dir = ([
    "west" : "/chapter/prologue/area/anshelm/room259",
    "east" : "/chapter/prologue/area/anshelm/room281",
    "south" : "/chapter/prologue/area/anshelm/room257",
  ]);

  set_light(1);
}
