inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Choked End";
  long_desc = "The surface dips and rises where blocks have settled, leaving sharp lips and hollows. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/indel/room1627",
  ]);

  set_light(1);
}
