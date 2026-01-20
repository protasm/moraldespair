inherit "room/room";

void create() {
  ::create();

    short_desc = "Inner Walk";
    long_desc = "A narrow run of cobbles skirts the wall, sunk and slick with damp. The high masonry is stained with mildew, and fallen stones crowd the edge of the path.";
    dest_dir = ([
      "east":"/chapter/prologue/area/ruined/room181",
      "west":"/chapter/prologue/area/ruined/room183",
    ]);

  set_light(1);
}

