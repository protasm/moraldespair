inherit "room/room";

void create() {
  ::create();

  short_desc = "Smeared Narrow Way";
  long_desc = "The floor is a churn of fractured stone and rubble, pressed flat by time. Walls to either side are chewed by blasts and blade scars, their faces peeled away. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1571", "east",
    "chapter/prologue/area/indel/room1569", "west",
  });

  set_light(1);
}
