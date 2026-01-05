inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallah's Flat:";
    long_desc = "Fallah's Flat:.\n";
    dest_dir = ({
        "domain/original/area/candera/room99", "north",
        "domain/original/area/candera/room101", "south",
        "domain/original/area/candera/room997", "east",
        "domain/original/area/candera/room505", "west",
    });
}
