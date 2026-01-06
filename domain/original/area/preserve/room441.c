inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tropical Forest";
    long_desc = "Tropical Forest.\n";
    dest_dir = ({
        "domain/original/area/preserve/room442", "south",
        "domain/original/area/preserve/room440", "north",
    });
}
