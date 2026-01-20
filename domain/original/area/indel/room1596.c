inherit "room/room";

void create() {
  ::create();

  short_desc = "Silted Cold Broken Bend";
  long_desc = "Grit and broken tiles lie in drifts, the ground uneven and tired. Blackened streaks and gouges run along the masonry, breaking any clean line. The passage angles hard here, squeezed between stone left to lean and settle. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ({
    "domain/original/area/indel/room1597", "north",
    "domain/original/area/indel/room1595", "east",
  });

  set_light(1);
}
