inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room560", "southwest",
        "domain/original/area/forest/room558", "west",
        "domain/original/area/forest/room573", "south",
    });
}
