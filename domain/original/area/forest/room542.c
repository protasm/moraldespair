inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room541", "southwest",
        "domain/original/area/forest/room543", "northeast",
        "domain/original/area/forest/room547", "east",
        "domain/original/area/forest/room548", "south",
    });
}
