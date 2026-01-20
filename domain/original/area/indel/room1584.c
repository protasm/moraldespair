inherit "room/room";

void create() {
  ::create();

  short_desc = "Sagging Cold Crossing";
  long_desc = "Split slabs tilt against each other, their edges worn to chalk. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way opens into a broad break where several ruined lines meet in silence. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1406", "north",
    "domain/original/area/indel/room1579", "south",
    "domain/original/area/indel/room1587", "east",
    "domain/original/area/indel/room1588", "west",
  });

  set_light(1);
}
