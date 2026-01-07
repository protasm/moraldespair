inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A dead end";
    long_desc = "A dead end.\n";
    dest_dir = ({
        "domain/original/area/balin/room629", "south",
    });
}
