inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southwest Corner";
    long_desc = "Southwest Corner.\n";
    dest_dir = ({
        "domain/original/area/candera/room37", "north",
        "domain/original/area/candera/room35", "east",
    });
}
