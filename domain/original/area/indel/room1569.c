inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Church Road Bend";
    long_desc = "Church Road Bend.\n";
    dest_dir = ({
        "domain/original/area/indel/room1568", "south",
        "domain/original/area/indel/room1570", "east",
    });
}
