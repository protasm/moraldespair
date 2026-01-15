inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "River-Main Junction";
    long_desc = "Two dead roads cross in a scatter of broken cobbles. A fractured drain grate\n"
              + "sits at the center, packed with mud and leaves.\n";
    dest_dir = ({
        "domain/original/area/vesla/room816", "south",
        "domain/original/area/vesla/room150", "west",
        "domain/original/area/vesla/room205", "east",
        "domain/original/area/vesla/room152", "north",
    });
}

