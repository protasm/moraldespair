inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park.\n";
    dest_dir = ({
        "domain/original/area/vesla/room117", "south",
        "domain/original/area/vesla/room228", "west",
        "domain/original/area/vesla/room172", "east",
        "domain/original/area/vesla/room232", "north",
    });
}
