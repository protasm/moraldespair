inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Road";
    long_desc = "Here the main road is flanked by crumbling foundations. A patch of nettles spills across the center line.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room160", "south",
        "chapter/prologue/area/ruined/room808", "east",
        "chapter/prologue/area/ruined/room162", "north",
    });
}

