inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Highland Avenue";
    long_desc = "Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/balin/room647", "south",
        "domain/original/area/balin/room642", "east",
        "domain/original/area/balin/room644", "north",
    });
}
