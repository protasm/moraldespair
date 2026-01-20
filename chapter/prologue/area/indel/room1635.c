inherit "room/room";

void create() {
  ::create();

  short_desc = "Eroded Silted Choked End";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Carved blocks are shattered and glazed in places, a mix of chisel scars and burn pits. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1401", "east",
  });

  set_light(1);
}
