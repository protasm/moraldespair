inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "General Store";
    long_desc = "General Store";
    dest_dir = ({
        "domain/original/area/vesla/room222", "west",
        "domain/original/area/vesla/room220", "east",
        "domain/original/area/vesla/room118", "north",
    });
}
