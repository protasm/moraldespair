inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Queen's Meadow";
    long_desc = "Queen's Meadow.\n";
    dest_dir = ({
        "domain/original/area/preserve/room446", "south",
        "domain/original/area/preserve/room448", "north",
    });
}
