inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East wing hallway";
    long_desc = "East wing hallway.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1371", "north",
    });
}
