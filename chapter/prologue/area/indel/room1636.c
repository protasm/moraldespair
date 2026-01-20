inherit "room/room";

void create() {
  ::create();

  short_desc = "Splintered Choked End";
  long_desc = "Rubble and crushed mortar blanket the surface, slick in places with old damp. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1401", "west",
  });

  set_light(1);
}
