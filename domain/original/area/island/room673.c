inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Seed Shop";
    long_desc = "Seed Shop.\n";
    dest_dir = ({
        "domain/original/area/island/room661", "north",
    });
}
