inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East of the waterfall";
    long_desc = "East of the waterfall.\n";
    dest_dir = ({
        "domain/original/area/balin/room623", "east",
        "domain/original/area/balin/room625", "west",
    });
}
