inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Wall Guard Station";
    long_desc = "East Wall Guard Station.\n";
    dest_dir = ({
        "domain/original/area/candera/room14", "north",
        "domain/original/area/candera/room16", "south",
        "domain/original/area/candera/room973", "east",
    });
}
