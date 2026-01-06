inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room578", "southwest",
        "domain/original/area/forest/room580", "northeast",
        "domain/original/area/forest/room596", "west",
        "domain/original/area/forest/room597", "north",
    });
}
