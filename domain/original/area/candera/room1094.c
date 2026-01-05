inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Weapon Master's Shop";
    long_desc = "Weapon Master's Shop.\n";
    dest_dir = ({
        "domain/original/area/candera/room90", "west",
    });
}
