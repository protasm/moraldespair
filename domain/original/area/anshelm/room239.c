inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Rue du Nord and Beitel Straat";
    long_desc = "Intersection of Rue du Nord and Beitel Straat.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room238", "south",
        "domain/original/area/anshelm/room414", "west",
        "domain/original/area/anshelm/room1185", "east",
        "domain/original/area/anshelm/room240", "north",
    });
}
