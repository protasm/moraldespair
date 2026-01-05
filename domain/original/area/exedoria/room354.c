inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mom's General Store";
    long_desc = "Mom's General Store.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room312", "east",
    });
}
