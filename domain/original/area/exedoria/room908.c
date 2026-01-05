inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Vine-covered Entry";
    long_desc = "Vine-covered Entry.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room910", "southwest",
        "domain/original/area/exedoria/room907", "southeast",
        "domain/original/area/exedoria/room909", "north",
    });
}
