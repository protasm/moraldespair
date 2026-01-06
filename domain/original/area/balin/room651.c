inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dwarven Shack";
    long_desc = "Dwarven Shack.\n";
    dest_dir = ({
        "domain/original/area/balin/room648", "north",
    });
}
