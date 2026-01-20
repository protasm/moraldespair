inherit "room/room";

void create() {
  ::create();

  short_desc = "Leaning Broken Bend";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1593", "south",
    "chapter/prologue/area/indel/room1595", "west",
  });

  set_light(1);
}
