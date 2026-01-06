inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hall of War";
    long_desc = "Hall of War.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1376", "west",
        "domain/original/area/pylus/room1385", "east",
        "domain/original/area/pylus/room1388", "south",
    });
}
