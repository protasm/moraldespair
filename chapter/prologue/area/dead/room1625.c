inherit "/chapter/prologue/std/room";

void create() {
  ::create();

  short_desc = "Silted Choked End";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "east" : "/chapter/prologue/area/dead/room1405",
  ]);

  set_light(1);
}
