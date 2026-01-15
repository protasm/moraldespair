inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wallside Way";
    long_desc = "The lane hugs the inner wall, its cobbles cracked and uneven beneath\n"
                + "drifts of grit. Moss climbs the cold stone blocks, and a broken\n"
                + "drainage channel runs dark and still.\n";
    dest_dir = ({
        "domain/original/area/vesla/room180", "east",
        "domain/original/area/vesla/room182", "west",
    });
}

