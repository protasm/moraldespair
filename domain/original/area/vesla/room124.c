inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A break in the coverage";
    long_desc = "A break in the coverage.\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "west",
        "domain/original/area/vesla/room123", "east",
        "domain/original/area/vesla/room412", "north",
    });
}
