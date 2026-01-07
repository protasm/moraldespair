inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The base of a waterfall";
    long_desc = "The base of a waterfall.\n";
    dest_dir = ({
        "domain/original/area/island/room624", "east",
    });
}
