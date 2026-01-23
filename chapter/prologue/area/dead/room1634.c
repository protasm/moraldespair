inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Choked End";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/dead/room1633",
  ]);

  set_light(1);
}
