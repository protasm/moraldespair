inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Suran's Flat";
    long_desc = "Suran's Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room88", "north",
        "domain/original/area/candera/room86", "south",
        "domain/original/area/candera/room1082", "west",
    });
}
