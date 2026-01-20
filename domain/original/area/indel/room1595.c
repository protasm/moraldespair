inherit "room/room";

void create() {
  ::create();

  short_desc = "Cold Narrow Way";
  long_desc = "Pitted stone stretches ahead, littered with chips and fragments. Blackened streaks and gouges run along the masonry, breaking any clean line. The way runs on in a narrow line, hemmed by broken walls left to weather. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1594", "east",
    "domain/original/area/indel/room1596", "west",
  });

  set_light(1);
}
