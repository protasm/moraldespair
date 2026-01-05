inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fallah's Flat:";
    long_desc = "Fallah's Flat:.\n";
    dest_dir = ({
        "domain/original/area/candera/room102", "north",
        "domain/original/area/candera/room104", "south",
        "domain/original/area/candera/room999", "east",
        "domain/original/area/candera/room998", "west",
    });
}
