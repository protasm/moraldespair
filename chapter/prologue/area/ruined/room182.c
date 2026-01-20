inherit "room/room";

void create() {
  ::create();

    short_desc = "Inner Walk";
    long_desc = "A narrow run of cobbles skirts the wall, sunk and slick with damp. The high masonry is stained with mildew, and fallen stones crowd the edge of the path.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room181", "east",
        "chapter/prologue/area/ruined/room183", "west",
    });

  set_light(1);
}

