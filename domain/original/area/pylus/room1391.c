inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Office of the Secretary";
    long_desc = "Office of the Secretary.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1261", "north",
    });
}
