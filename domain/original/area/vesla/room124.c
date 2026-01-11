inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Canopy";
  long_desc = "The cover above the walk has failed, opening to a pale strip of sky. Loose\n"
              + "stones and splintered wood lie scattered, and the ground shows long years of\n"
              + "weathering.\n";
  dest_dir = ({
    "domain/original/area/vesla/room125", "west",
    "domain/original/area/vesla/room123", "east",
    "domain/original/area/vesla/room412", "north",
  });
}
