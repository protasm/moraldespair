inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A path through the forest";
    long_desc = "A path through the forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room591", "west",
        "domain/original/area/forest/room578", "south",
        "domain/original/area/forest/room533", "southwest",
        "domain/original/area/forest/room597", "northeast",
        "domain/original/area/forest/room579", "east",
        "domain/original/area/forest/room590", "north",
    });
}
