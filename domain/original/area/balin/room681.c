inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Audience Hall";
    long_desc = "Audience Hall.\n";
    dest_dir = ({
        "domain/original/area/balin/room682", "west",
        "domain/original/area/balin/room680", "south",
    });
}
