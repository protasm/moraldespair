inherit "room/room";

void reset(int arg) {
  if (arg)
    return;

  set_light(1);

  short_desc = "Twin Shadows";
  long_desc = "Two battered towers hem in this passage, their upper floors cracked and open to the sky. Loose stones and damp rubble gather where a wooden span once steadied the gap.";
  dest_dir = ({
    "domain/original/area/vesla/room753", "south",
    "domain/original/area/vesla/room755", "north",
  });
}
