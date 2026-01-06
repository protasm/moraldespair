inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Highland Avenue";
    long_desc = "Highland Avenue.\n";
    dest_dir = ({
        "domain/original/area/balin/room652", "west",
        "domain/original/area/balin/room648", "south",
    });
}
