inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple";
    long_desc = "Temple.\n";
    dest_dir = ({
        "domain/original/area/island/room611", "west",
        "domain/original/area/island/room714", "east",
        "domain/original/area/island/room716", "north",
    });
}
