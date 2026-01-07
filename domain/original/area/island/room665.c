inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East End of Balin Road";
    long_desc = "East End of Balin Road.\n";
    dest_dir = ({
        "domain/original/area/balin/room664", "west",
        "domain/original/area/balin/room666", "south",
    });
}
