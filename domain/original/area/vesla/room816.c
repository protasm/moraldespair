inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Stone Span";
  long_desc = "The bridge stones are slick with moss, the span silent and dilapidated. Rust\n"
        + "marks the grooves of an old gate, and dust and mildew cling to the guard\n"
        + "alcove in disrepair.\n";
  dest_dir = ({
    "domain/original/area/vesla/room151", "north",
  });
}

