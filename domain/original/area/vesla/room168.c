inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of North Main and Wall Street";
    long_desc = "Intersection of North Main and Wall Street\n";
    dest_dir = ({
        "domain/original/area/vesla/room167", "south",
        "domain/original/area/vesla/room793", "west",
        "domain/original/area/vesla/room170", "east",
        "domain/original/area/vesla/room169", "north",
    });
}

