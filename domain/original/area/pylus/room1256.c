inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before the Palace";
    long_desc = "Before the Palace.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1255", "south",
        "domain/original/area/pylus/room1257", "north",
    });
}
