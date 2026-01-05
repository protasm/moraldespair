inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Suran's Flat";
    long_desc = "Suran's Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room91", "north",
        "domain/original/area/candera/room89", "south",
        "domain/original/area/candera/room1094", "east",
        "domain/original/area/candera/room1093", "west",
    });
}
