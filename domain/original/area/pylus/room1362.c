inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Guard Post";
    long_desc = "Guard Post.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1258", "west",
        "domain/original/area/pylus/room1392", "east",
        "domain/original/area/pylus/room1395", "north",
    });
}
