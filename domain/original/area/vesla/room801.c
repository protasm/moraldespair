inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Stale Cut";
  long_desc = "The dead-end passage is choked with grit and damp cobbles, quiet under sagging walls. Faint nail holes in the stone imply shelving or a lean-to long since gone.";
  dest_dir = ({
    "domain/original/area/vesla/room800", "west",
  });
}
