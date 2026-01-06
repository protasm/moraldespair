inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rotunda of War";
    long_desc = "Rotunda of War.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1385", "west",
    });
}
