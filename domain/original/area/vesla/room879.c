inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Broken Desk";
  long_desc = "A line of battered cubbies slumps against the wall, clogged with dust. A collapsed counter and scattered tags hint at messages once sorted here, now lost.";
  dest_dir = ({
    "domain/original/area/vesla/room126", "south",
  });
}
