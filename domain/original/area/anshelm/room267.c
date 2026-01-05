inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Rue du Nord and Kasernegade";
    long_desc = "Intersection of Rue du Nord and Kasernegade.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room266", "south",
        "domain/original/area/anshelm/room268", "west",
        "domain/original/area/anshelm/room276", "east",
        "domain/original/area/anshelm/room273", "north",
    });
}
