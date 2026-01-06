inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern District";
    long_desc = "Eastern District.\n";
    dest_dir = ({
        "domain/original/area/balin/room731", "south",
        "domain/original/area/balin/room729", "north",
    });
}
