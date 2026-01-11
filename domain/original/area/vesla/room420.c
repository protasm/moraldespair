inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Nave";
  long_desc = "The nave stands in silence, its benches split and furred with mildew. A broken\n"
              + "basin and a faded sigil suggest solace once offered here, now left to dust.\n";
  dest_dir = ({
    "domain/original/area/vesla/room130", "north",
  });
}
