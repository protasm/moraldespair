inherit "room/room";

void create() {
  ::create();

  short_desc = "Stone Span";
  long_desc = "The bridge stones are slick with moss, the span silent and weatherworn. Rust marks the grooves of an old gate, and dust and mildew cling to the guard alcove, now sagged and empty.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room151", "north",
  });

  set_light(1);
}
