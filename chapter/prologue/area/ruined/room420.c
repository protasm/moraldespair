inherit "room/room";

void create() {
  ::create();

  short_desc = "Quiet Nave";
  long_desc = "The nave stands in silence, its benches split and furred with mildew. A broken basin and a faded sigil suggest solace once offered here, now left to dust.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room130", "north",
  });

  set_light(1);
}
