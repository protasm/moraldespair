inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Broken Bend";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/indel/room1582",
    "down" : "/chapter/prologue/area/indel/room1653",
  ]);

  set_light(1);
}
