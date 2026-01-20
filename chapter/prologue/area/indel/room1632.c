inherit "room/room";

void create() {
  ::create();

  short_desc = "Ashen Silted Choked End";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1631", "east",
  });

  set_light(1);
}
