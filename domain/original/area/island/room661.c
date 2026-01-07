inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Balin Road";
    long_desc = "Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room660", "west",
        "domain/original/area/balin/room662", "east",
        "domain/original/area/balin/room673", "south",
    });
}
