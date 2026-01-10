inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Collapsed Structure";
    long_desc = "Collapsed Structure";
    dest_dir = ({
        "domain/original/area/vesla/room222", "west",
        "domain/original/area/vesla/room220", "east",
        "domain/original/area/vesla/room118", "north",
    });
}
