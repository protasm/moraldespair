inherit "/room/room";

void create() {
  ::create();

  short_desc = "Eroded Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "north" : "/chapter/prologue/area/dead/room1579",
    "south" : "/chapter/prologue/area/dead/room1586",
  ]);

  set_light(1);
}
