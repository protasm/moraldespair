inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Wall Guard Station";
    long_desc = "East Wall Guard Station.\n";
    dest_dir = ({
        "domain/original/area/candera/room986", "north",
        "domain/original/area/candera/room974", "south",
        "domain/original/area/candera/room15", "west",
    });
}
