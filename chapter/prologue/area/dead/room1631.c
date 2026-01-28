inherit "/room/room";

void create() {
  ::create();

  short_desc = "Silted Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. The remains of pillars stand jagged, split and fused by old force. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1402",
    "west" : "/chapter/prologue/area/dead/room1632",
  ]);

  set_light(1);
}
