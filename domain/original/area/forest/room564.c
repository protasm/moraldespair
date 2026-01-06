inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room553", "west",
        "domain/original/area/forest/room568", "south",
        "domain/original/area/forest/room565", "southwest",
        "domain/original/area/forest/room563", "northeast",
        "domain/original/area/forest/room569", "east",
        "domain/original/area/forest/room554", "north",
    });
}
