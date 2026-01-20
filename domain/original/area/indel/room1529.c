inherit "room/room";

void create() {
  ::create();

  short_desc = "Faded Narrow Way";
  long_desc = "Broken paving lies in uneven ridges, with fine dust caked between. The stonework is torn open, exposing fill and roots, with scorch marks in the cracks. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1528", "north",
    "domain/original/area/indel/room1530", "south",
  });

  set_light(1);
}
