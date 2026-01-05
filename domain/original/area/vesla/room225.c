inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Brimstone";
    long_desc = "Brimstone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room224", "east",
        "domain/original/area/vesla/room122", "north",
    });
}
