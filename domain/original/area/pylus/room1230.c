inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Large field";
    long_desc = "Large field.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1239", "west",
        "domain/original/area/pylus/room1229", "northeast",
    });
}
