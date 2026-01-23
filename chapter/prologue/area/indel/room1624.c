inherit "room/room";

void create() {
  ::create();

  short_desc = "Sundered Choked End";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/indel/room1509",
  ]);

  set_light(1);
}
