inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room549", "west",
        "domain/original/area/forest/room564", "south",
        "domain/original/area/forest/room553", "southwest",
        "domain/original/area/forest/room555", "northeast",
        "domain/original/area/forest/room563", "east",
        "domain/original/area/forest/room548", "north",
    });
}
