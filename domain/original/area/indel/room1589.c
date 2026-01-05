inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Silver Griffin";
    long_desc = "The Silver Griffin.\n";
    dest_dir = ({
        "domain/original/area/indel/room1408", "north",
        "domain/original/area/indel/room1588", "east",
        "domain/original/area/indel/room1590", "west",
    });
}
