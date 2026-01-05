inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dean's office";
    long_desc = "Dean's office.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room900", "south",
    });
}
