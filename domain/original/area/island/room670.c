inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Elven Mercantile";
    long_desc = "Elven Mercantile.\n";
    dest_dir = ({
        "domain/original/area/balin/room663", "north",
    });
}
