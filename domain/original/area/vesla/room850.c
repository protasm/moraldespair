inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Silent Hearth";
  long_desc = "A wide, cold hearth sits beneath a soot-dark mantle, the room silent and ruined. Rotted tables lean in dust and mildew, and the common space is left to sag.";
  dest_dir = ({
    "domain/original/area/vesla/room142", "west",
    "domain/original/area/vesla/room852", "east",
    "domain/original/area/vesla/room851", "north",
  });
}
