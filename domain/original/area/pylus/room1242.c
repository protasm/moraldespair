inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Natatorium";
    long_desc = "Natatorium.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1241", "north",
    });
}
