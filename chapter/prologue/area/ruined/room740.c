inherit "room/room";

void create() {
  ::create();

    short_desc = "Dusty Stall";
    long_desc = "A small room with a low counter sits abandoned, its shelves stripped clean. The air is stale with rot, and broken pegs show where trade once hung.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room190", "north",
    });

  set_light(1);
}

