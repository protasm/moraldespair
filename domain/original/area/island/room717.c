inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Poison Shop";
    long_desc = "Poison Shop.\n";
    dest_dir = ({
        "domain/original/area/island/room635", "north",
    });
}
