inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Power System Generator";
    long_desc = "Power System Generator.\n";
    dest_dir = ({
        "domain/original/area/balin/room692", "east",
        "domain/original/area/balin/room618", "west",
    });
}
