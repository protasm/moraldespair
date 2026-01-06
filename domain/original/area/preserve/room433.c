inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Waterfall";
    long_desc = "Waterfall.\n";
    dest_dir = ({
        "domain/original/area/preserve/room432", "east",
    });
}
