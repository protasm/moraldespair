inherit "room/room";

void create() {
  ::create();

  short_desc = "Pitted Bleached Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "chapter/prologue/area/indel/room1418", "north",
    "chapter/prologue/area/indel/room1420", "south",
  });

  set_light(1);
}
