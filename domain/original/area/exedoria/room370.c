inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beginning of park path";
    long_desc = "Beginning of park path.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room291", "south",
        "domain/original/area/exedoria/room371", "north",
    });
}
