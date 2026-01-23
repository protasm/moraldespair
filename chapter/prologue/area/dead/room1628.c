inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Broken Bend";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. The remains of pillars stand jagged, split and fused by old force. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1403",
    "down" : "/chapter/prologue/area/dead/room1629",
  ]);

  set_light(1);
}
