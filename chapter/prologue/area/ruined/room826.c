inherit "room/room";

void reset(int arg) {
  if (arg) {
    return;
  }

  set_light(1);

  short_desc = "Veiled Room";
  long_desc = "A narrow chamber holds a sagging bedframe and a tangle of torn veil cloth. Mildew creeps along the walls, and the floorboards sag under layers of dust and silence.";
  dest_dir = ({
    "chapter/prologue/area/ruined/room825", "east",
  });
}
