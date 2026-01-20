inherit "room/room";

void create() {
  ::create();

  short_desc = "Veiled Room";
  long_desc = "A narrow chamber holds a sagging bedframe and a tangle of torn veil cloth. Mildew creeps along the walls, and the floorboards sag under layers of dust and silence.";
  dest_dir = ([
    "east":"/chapter/prologue/area/ruined/room825",
  ]);

  set_light(1);
}
