inherit "room/room";

void create() {
  ::create();

  short_desc = "Split Narrow Way";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1568", "north",
    "chapter/prologue/area/indel/room1566", "south",
  });

  set_light(1);
}
