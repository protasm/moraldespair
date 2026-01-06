inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Waiting room";
    long_desc = "Waiting room.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1221", "east",
        "domain/original/area/pylus/room1219", "south",
    });
}
