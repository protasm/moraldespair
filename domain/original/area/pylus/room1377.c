inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple hallway";
    long_desc = "Temple hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1378", "south",
        "domain/original/area/pylus/room1376", "north",
    });
}
