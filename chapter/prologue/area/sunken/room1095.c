inherit "/room/room";

void create() {
  ::create();

  short_desc = "Burned Run";
  long_desc = "A crooked passage threads between leaning fragments of masonry. Loose stones shift with each step, exposing darker layers below. The place feels picked clean, stripped of timber and metal.";
  dest_dir = ({
    "chapter/prologue/area/sunken/room75", "north",
  });

  set_light(1);
}
