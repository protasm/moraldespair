inherit "/room/room";

void create() {
  ::create();

  short_desc = "Cold Choked End";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/dead/room1600",
  ]);

  set_light(1);
}
