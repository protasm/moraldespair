inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Empty Shopfront";
  long_desc = "Rotted timbers sag above a cramped room, the floor buried in grit and splintered boards. Rust-flecked hooks and a few warped racks cling to the walls, hinting at what once lined them. A stale hush and mildew settle over the hollow space.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room231", "south",
  });
}
