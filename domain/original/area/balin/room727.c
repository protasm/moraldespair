inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Western District";
    long_desc = "Western District.\n";
    dest_dir = ({
        "domain/original/area/balin/room728", "south",
        "domain/original/area/balin/room726", "north",
    });
}
