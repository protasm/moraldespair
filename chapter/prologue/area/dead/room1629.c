inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble Silted Choked End";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "up" : "/chapter/prologue/area/dead/room1628",
  ]);

  set_light(1);
}
