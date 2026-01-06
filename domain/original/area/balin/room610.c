inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Silver Street and Balin Road";
    long_desc = "Intersection of Silver Street and Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room609", "south",
        "domain/original/area/balin/room635", "west",
        "domain/original/area/balin/room660", "east",
        "domain/original/area/balin/room611", "north",
    });
}
