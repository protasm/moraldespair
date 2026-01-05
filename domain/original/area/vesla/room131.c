inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Westroad";
    long_desc = "Westroad.\n";
    dest_dir = ({
        "domain/original/area/vesla/room132", "west",
        "domain/original/area/vesla/room130", "east",
        "domain/original/area/vesla/room858", "north",
    });
}
