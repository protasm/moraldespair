inherit "room/room";

void create() {
  ::create();

  short_desc = "Worn Choked End";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1514",
  ]);

  set_light(1);
}
