inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Sour Cut";
  long_desc = "The passage bends in shadow, damp with rot and flecked with peeling lime. A shallow gutter runs along the base of the wall, a remnant of old refuse flow.";
  dest_dir = ({
    "domain/original/area/vesla/room797", "south",
    "domain/original/area/vesla/room799", "north",
  });
}
