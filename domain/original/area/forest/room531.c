inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room530", "southwest",
        "domain/original/area/forest/room539", "northeast",
        "domain/original/area/forest/room551", "east",
    });
}
