inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Park path on the hill";
    long_desc = "Park path on the hill.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room371", "south",
        "domain/original/area/exedoria/room374", "north",
    });
}
