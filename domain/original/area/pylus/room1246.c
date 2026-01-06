inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Butcher shop";
    long_desc = "Butcher shop.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1227", "west",
    });
}
