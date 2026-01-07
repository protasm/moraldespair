inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Harem";
    long_desc = "West Harem.\n";
    dest_dir = ({
        "domain/original/area/island/room699", "east",
        "domain/original/area/island/room697", "west",
    });
}
