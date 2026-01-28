inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1581",
    "west" : "/chapter/prologue/area/dead/room1579",
  ]);

  set_light(1);
}
