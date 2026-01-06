inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A path through the forest";
    long_desc = "A path through the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room548", "west",
        "domain/original/area/forest/room563", "south",
        "domain/original/area/forest/room554", "southwest",
        "domain/original/area/forest/room556", "northeast",
        "domain/original/area/forest/room562", "east",
        "domain/original/area/forest/room547", "north",
    });
}
