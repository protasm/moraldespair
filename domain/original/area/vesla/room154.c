inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "South Main Street";
    long_desc = "South Main Street\n";
    dest_dir = ({
        "domain/original/area/vesla/room153", "south",
        "domain/original/area/vesla/room821", "east",
        "domain/original/area/vesla/room155", "north",
    });
}

