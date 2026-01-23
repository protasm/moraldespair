inherit "room/room";

void create() {
  ::create();

  short_desc = "Shattered Cold Choked End";
  long_desc = "Stone underfoot is split into plates, with grit and ash packed into the seams. Blackened streaks and gouges run along the masonry, breaking any clean line. A collapsed heap chokes the line, the passage left to cave in. Thin lichen mats the shaded edges, and the air tastes of wet dust.";
  dest_dir = ([
    "west" : "/chapter/prologue/area/indel/room1584",
  ]);

  set_light(1);
}
