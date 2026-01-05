inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A peaceful park";
    long_desc = "A peaceful park.\n";
    dest_dir = ({
        "domain/original/area/vesla/sanctuary", "north",
        "domain/original/area/vesla/peaceful_park2", "south",
        "domain/original/area/vesla/sanctuary", "east",
        "domain/original/area/vesla/sanctuary", "west",
    });
}
