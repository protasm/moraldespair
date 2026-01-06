inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Highland Avenue";
    long_desc = "Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/balin/room651", "south",
        "domain/original/area/balin/room644", "west",
        "domain/original/area/balin/room649", "east",
        "domain/original/area/balin/room650", "north",
    });
}
