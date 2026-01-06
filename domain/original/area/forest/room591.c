inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room592", "west",
        "domain/original/area/forest/room533", "south",
        "domain/original/area/forest/room534", "southwest",
        "domain/original/area/forest/room590", "northeast",
        "domain/original/area/forest/room596", "east",
        "domain/original/area/forest/room593", "north",
    });
}
