inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Frenchie's II";
    long_desc = "Frenchie's II.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room300", "north",
    });
}
