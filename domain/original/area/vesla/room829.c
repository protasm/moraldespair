inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Quiet Parlor";
  long_desc = "This back room is heavy with stale air, its cushions reduced to moldy husks. A\n"
              + "low screen has fallen across the floor, and the only scent left is damp wood\n"
              + "and dust.\n";
  dest_dir = ({
    "domain/original/area/vesla/room825", "down",
  });
}
