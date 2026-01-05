inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dining commons";
    long_desc = "Dining commons.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room894", "north",
    });
}
