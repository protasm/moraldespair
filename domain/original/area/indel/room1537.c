inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Embassy Row";
    long_desc = "Embassy Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1538", "east",
        "domain/original/area/indel/room1536", "west",
    });
}
