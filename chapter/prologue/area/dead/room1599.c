inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Cold Choked End";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1598",
  ]);

  set_light(1);
}
