inherit "room/room";

void create() {
  ::create();

    short_desc = "Dusty Cots";
    long_desc = "A tight room of empty pallets sits in silence, the straw long gone. Rot has crept up the posts, and the air is stale with old sweat and mildew.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room746",
      "south":"/chapter/prologue/area/ruined/room741",
    ]);

  set_light(1);
}

