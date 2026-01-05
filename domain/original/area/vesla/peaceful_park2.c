inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park.\n";
    dest_dir = ({
        "domain/original/area/vesla/peaceful_park1", "north",
        "domain/original/area/vesla/shaded_walk1", "south",
        "domain/original/area/vesla/sanctuary", "east",
        "domain/original/area/vesla/sanctuary", "west",
    });
}
