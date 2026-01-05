inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Exedoria Pet Cemetary";
    long_desc = "Exedoria Pet Cemetary.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room371", "east",
    });
}
