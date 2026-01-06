inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The harem";
    long_desc = "The harem.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1396", "west",
        "domain/original/area/pylus/room1400", "north",
    });
}
