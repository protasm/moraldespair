inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Back Room";
    long_desc = "The Back Room\n";
    dest_dir = ({
        "domain/original/area/vesla/room230", "east",
        "domain/original/area/vesla/room814", "north",
    });
}
