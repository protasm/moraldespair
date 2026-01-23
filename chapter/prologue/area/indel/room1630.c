inherit "room/room";

void create() {
  ::create();

  short_desc = "Collapsed Choked End";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/indel/room1403",
  ]);

  set_light(1);
}
