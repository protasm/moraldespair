inherit "room/room";

void create() {
  ::create();

  short_desc = "Dulled Sunk Broken Bend";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "south" : "/chapter/prologue/area/indel/room1568",
    "east" : "/chapter/prologue/area/indel/room1570",
  ]);

  set_light(1);
}
