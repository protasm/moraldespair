inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room543", "southwest",
        "domain/original/area/forest/room545", "east",
        "domain/original/area/forest/room546", "south",
    });
}
