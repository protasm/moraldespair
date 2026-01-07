inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Eastern Chamber";
    long_desc = "Eastern Chamber.\n";
    dest_dir = ({
        "domain/original/area/balin/room672", "east",
        "domain/original/area/balin/room714", "west",
    });
}
