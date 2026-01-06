inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Short path";
    long_desc = "Short path.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1375", "south",
        "domain/original/area/pylus/room1253", "north",
    });
}
