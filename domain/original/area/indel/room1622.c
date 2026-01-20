inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Choked End";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. The remains of pillars stand jagged, split and fused by old force. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1511", "south",
  });

  set_light(1);
}
