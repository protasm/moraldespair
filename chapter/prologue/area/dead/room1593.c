inherit "room/room";

void create() {
  ::create();

  short_desc = "Seamed Cold Broken Bend";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1594",
    "west" : "/chapter/prologue/area/dead/room1592",
  ]);

  set_light(1);
}
