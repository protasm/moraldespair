inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A forest path";
    long_desc = "A forest path.\n";
    dest_dir = ({
        "domain/original/area/forest/room533", "northeast",
        "domain/original/area/forest/room532", "east",
        "domain/original/area/forest/room534", "north",
    });
}
