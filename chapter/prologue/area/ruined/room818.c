inherit "room/room";

void create() {
  ::create();

  short_desc = "Gilded Ruin";
  long_desc = "The high chamber is stripped to its bones, yet traces of gilt cling to cracked molding. Damp has streaked the walls, and a heap of sagged cushions lies in mildew and silence near a cold firepit.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room817", "down",
  });

  set_light(1);
}
