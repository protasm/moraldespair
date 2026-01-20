inherit "room/room";

void create() {
  ::create();

  short_desc = "Cracked Narrow Way";
  long_desc = "Loose stones shift underfoot, buried in silt and powdered mortar. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1574", "east",
    "chapter/prologue/area/indel/room1572", "west",
  });

  set_light(1);
}
