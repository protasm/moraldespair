inherit "room/room";

void create() {
  ::create();

  short_desc = "Sagging Bleached Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. Leaning walls show long cuts and scorch trails, as if steel and heat worried them for hours. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1412", "east",
    "domain/original/area/indel/room1414", "west",
  });

  set_light(1);
}
