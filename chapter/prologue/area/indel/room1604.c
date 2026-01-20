inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Choked End";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1603", "west",
  });

  set_light(1);
}
