inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Stall";
    long_desc = "A small room with a low counter sits abandoned, its shelves stripped clean. The air is stale with rot, and broken pegs show where trade once hung.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room190", "north",
    });
}

