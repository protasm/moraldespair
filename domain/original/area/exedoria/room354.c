inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Fragmented Walls";
    long_desc = "Fragmented Walls.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room312", "east",
    });
}
