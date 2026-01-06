inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of temple hallway";
    long_desc = "End of temple hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1380", "west",
        "domain/original/area/pylus/room1379", "east",
        "domain/original/area/pylus/room1377", "north",
    });
}
