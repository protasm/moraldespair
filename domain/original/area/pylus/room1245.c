inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Herb garden";
    long_desc = "Herb garden.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1244", "north",
    });
}
