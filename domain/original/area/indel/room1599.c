inherit "room/room";

void create() {
  ::create();

  short_desc = "Ruined Cold Choked End";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1598", "south",
  });

  set_light(1);
}
