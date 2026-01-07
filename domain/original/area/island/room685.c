inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lady Roland's Bedroom";
    long_desc = "Lady Roland's Bedroom.\n";
    dest_dir = ({
        "domain/original/area/island/room684", "north",
    });
}
