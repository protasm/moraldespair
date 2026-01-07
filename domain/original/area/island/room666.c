inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Arched Gates";
    long_desc = "Arched Gates.\n";
    dest_dir = ({
        "domain/original/area/balin/room665", "north",
    });
}
