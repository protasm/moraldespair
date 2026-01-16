inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Empty Shopfront";
  long_desc =
  "Rotted timbers sag above a cramped room, the floor buried in grit\n"
  "and splintered boards. Rust-flecked hooks and a few warped racks\n"
  "cling to the walls, hinting at what once lined them. A stale hush\n"
  "and mildew settle over the hollow space.";
  dest_dir = ({
    "domain/original/area/vesla/room231", "south",
  });
}
