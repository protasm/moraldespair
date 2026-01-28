inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Scorched Broken Bend";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. The remains of pillars stand jagged, split and fused by old force. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/dead/room1637",
    "west" : "/chapter/prologue/area/dead/room1404",
  ]);

  set_light(1);
}
