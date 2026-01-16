inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Sour Cut";
  long_desc = "The passage bends in shadow, damp with rot and flecked with peeling\n"
    "lime. A shallow gutter runs along the base of the wall, a remnant of\n"
    "old refuse flow.\n";
  dest_dir = ({
    "domain/original/area/vesla/room797", "south",
    "domain/original/area/vesla/room799", "north",
  });
}
