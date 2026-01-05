inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to the Northeast Tower";
    long_desc = "Entrance to the Northeast Tower.\n";
    dest_dir = ({
        "domain/original/area/candera/room8", "north",
        "domain/original/area/candera/room10", "south",
    });
}
