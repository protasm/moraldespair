inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Krakenwater";
    long_desc = "Krakenwater.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "west",
    });
}
