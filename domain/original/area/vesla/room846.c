inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burned Area";
    long_desc = "Burned Area\n";
    dest_dir = ({
        "domain/original/area/vesla/room845", "west",
        "domain/original/area/vesla/room147", "north",
    });
}
