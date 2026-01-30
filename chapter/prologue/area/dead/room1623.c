inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Cracked Silted Narrow Way";
  long_desc = "The ground is a mosaic of cracked slabs and loose grit, dulled by age. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1643",
    "south" : "/chapter/prologue/area/dead/room1510",
  ]);
}
