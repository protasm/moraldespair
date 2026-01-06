inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A path through the forest";
    long_desc = "A path through the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room568", "southwest",
        "domain/original/area/forest/room570", "northeast",
        "domain/original/area/forest/room564", "west",
        "domain/original/area/forest/room563", "north",
    });
}
