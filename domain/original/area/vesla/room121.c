inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A shaded walk";
    long_desc = "A shaded walk\n";
    dest_dir = ({
        "domain/original/area/vesla/room224", "south",
        "domain/original/area/vesla/room122", "west",
        "domain/original/area/vesla/room120", "east",
        "domain/original/area/vesla/room425", "north",
    });
}

