inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Zoman's Flat";
    long_desc = "Zoman's Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room78", "north",
        "domain/original/area/candera/room80", "south",
        "domain/original/area/candera/room1096", "east",
    });
}
