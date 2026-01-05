inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A shaded walk";
    long_desc = "A shaded walk.\n";
    dest_dir = ({
        "domain/original/area/vesla/room225", "south",
        "domain/original/area/vesla/room123", "west",
        "domain/original/area/vesla/room121", "east",
        "domain/original/area/vesla/room410", "north",
    });
}
