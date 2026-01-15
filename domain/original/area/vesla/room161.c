inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Road";
    long_desc = "Here the main road is flanked by crumbling foundations. A patch of nettles\n"
              + "spills across the center line.\n";
    dest_dir = ({
        "domain/original/area/vesla/room160", "south",
        "domain/original/area/vesla/room808", "east",
        "domain/original/area/vesla/room162", "north",
    });
}

