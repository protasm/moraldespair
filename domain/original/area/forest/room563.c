inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest";
    long_desc = "A forest.\n";
    dest_dir = ({
        "domain/original/area/forest/room554", "west",
        "domain/original/area/forest/room569", "south",
        "domain/original/area/forest/room564", "southwest",
        "domain/original/area/forest/room562", "northeast",
        "domain/original/area/forest/room570", "east",
        "domain/original/area/forest/room555", "north",
    });
}
