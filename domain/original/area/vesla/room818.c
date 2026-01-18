inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Gilded Ruin";
  long_desc = "The high chamber is stripped to its bones, yet traces of gilt cling to cracked molding. Damp has streaked the walls, and a heap of sagged cushions lies in mildew and silence near a cold firepit.";
  dest_dir = ({
    "domain/original/area/vesla/room817", "down",
  });
}
