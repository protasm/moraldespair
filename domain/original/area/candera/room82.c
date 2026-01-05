inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Zoman's Flat";
    long_desc = "Zoman's Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room81", "north",
        "domain/original/area/candera/room83", "south",
        "domain/original/area/candera/room1098", "east",
        "domain/original/area/candera/room1097", "west",
    });
}
