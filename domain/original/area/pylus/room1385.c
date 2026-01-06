inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of War";
    long_desc = "Hall of War.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1386", "east",
        "domain/original/area/pylus/room1384", "west",
    });
}
