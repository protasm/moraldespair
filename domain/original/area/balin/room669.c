inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Office";
    long_desc = "Office.\n";
    dest_dir = ({
        "domain/original/area/balin/room668", "south",
    });
}
