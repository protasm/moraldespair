inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Jagged Cold Narrow Way";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1582",
    "west" : "/chapter/prologue/area/dead/room1580",
  ]);

  set_light(1);
}
