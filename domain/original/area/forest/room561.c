inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room556", "west",
        "domain/original/area/forest/room571", "south",
        "domain/original/area/forest/room562", "southwest",
        "domain/original/area/forest/room560", "northeast",
        "domain/original/area/forest/room572", "east",
        "domain/original/area/forest/room557", "north",
    });
}
