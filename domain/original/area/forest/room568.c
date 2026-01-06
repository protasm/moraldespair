inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room574", "southwest",
        "domain/original/area/forest/room569", "northeast",
        "domain/original/area/forest/room565", "west",
        "domain/original/area/forest/room564", "north",
    });
}
