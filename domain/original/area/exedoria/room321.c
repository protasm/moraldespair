inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Junk yard";
    long_desc = "Junk yard.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room315", "south",
    });
}
