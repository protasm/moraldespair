inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A clearing in the forest";
    long_desc = "A clearing in the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room579", "southwest",
        "domain/original/area/forest/room581", "northeast",
        "domain/original/area/forest/room597", "west",
        "domain/original/area/forest/room598", "north",
    });
}
