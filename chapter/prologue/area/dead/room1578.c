inherit "/room/room";

void create() {
  ::create();

  short_desc = "Charred Cold Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1579",
    "west" : "/chapter/prologue/area/dead/room1577",
  ]);

  set_light(1);
}
