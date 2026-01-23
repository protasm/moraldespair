inherit "room/room";

void create() {
  ::create();

  short_desc = "Smeared Cold Choked End";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Fragments of arches and lintels hang at odd angles, cut and burned through. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/indel/room1602",
  ]);

  set_light(1);
}
