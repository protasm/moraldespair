inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Statued hallway";
    long_desc = "Statued hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1363", "east",
        "domain/original/area/pylus/room1365", "west",
    });
}
