inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Harem";
    long_desc = "West Harem.\n";
    dest_dir = ({
        "domain/original/area/balin/room699", "east",
        "domain/original/area/balin/room697", "west",
    });
}
