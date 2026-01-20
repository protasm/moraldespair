inherit "room/room";

void create() {
  ::create();

  short_desc = "Pitted Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Masonry slumps inward, its edges scored and melted in places. The way runs on in a narrow line, hemmed by broken walls left to weather. Moss and pale mold cling to the damp pockets, and nothing moves except drifting grit.";
  dest_dir = ({
    "domain/original/area/indel/room1556", "east",
    "domain/original/area/indel/room1554", "west",
  });

  set_light(1);
}
