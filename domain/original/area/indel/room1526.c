inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1525", "north",
    "domain/original/area/indel/room1527", "south",
  });

  set_light(1);
}
