inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A path in the forest";
    long_desc = "A path in the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room557", "west",
        "domain/original/area/forest/room572", "south",
        "domain/original/area/forest/room561", "southwest",
        "domain/original/area/forest/room559", "northeast",
        "domain/original/area/forest/room573", "east",
        "domain/original/area/forest/room558", "north",
    });
}
