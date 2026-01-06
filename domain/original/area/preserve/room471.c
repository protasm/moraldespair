inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Tropical Landscape";
    long_desc = "Tropical Landscape.\n";
    dest_dir = ({
        "domain/original/area/preserve/room470", "south",
        "domain/original/area/preserve/room472", "north",
    });
}
