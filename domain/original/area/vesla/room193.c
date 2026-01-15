inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Rapier Way";
  long_desc = "Rapier Way begins between tight stone walls, its paving set in narrow strips.\n"
              + "The stones are chipped and uneven, and dark dust has gathered deep in the\n"
              + "seams.\n";
  dest_dir = ({
    "domain/original/area/vesla/room194", "east",
    "domain/original/area/vesla/room137", "west",
  });
}
