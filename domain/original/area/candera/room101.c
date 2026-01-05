inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallah's Flat";
    long_desc = "Fallah's Flat.\n";
    dest_dir = ({
        "domain/original/area/candera/room100", "north",
        "domain/original/area/candera/room102", "south",
    });
}
