inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gymnasium hallway";
    long_desc = "Gymnasium hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1242", "south",
        "domain/original/area/pylus/room1239", "north",
    });
}
