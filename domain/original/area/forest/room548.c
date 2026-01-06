inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A path in the forest";
    long_desc = "A path in the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room541", "west",
        "domain/original/area/forest/room554", "south",
        "domain/original/area/forest/room549", "southwest",
        "domain/original/area/forest/room547", "northeast",
        "domain/original/area/forest/room555", "east",
        "domain/original/area/forest/room542", "north",
    });
}
