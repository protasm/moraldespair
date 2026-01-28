inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cold Choked End";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1585",
  ]);

  set_light(1);
}
