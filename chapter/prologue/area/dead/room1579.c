inherit "room/room";

void create() {
  ::create();

  short_desc = "Rubble Crossing";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way opens into a broad break where several ruined lines meet in silence. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1584",
    "south" : "/chapter/prologue/area/dead/room1585",
    "east" : "/chapter/prologue/area/dead/room1580",
    "west" : "/chapter/prologue/area/dead/room1578",
  ]);

  set_light(1);
}
