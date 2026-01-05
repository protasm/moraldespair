inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Martial Row";
    long_desc = "West Martial Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1542", "east",
        "domain/original/area/indel/room1540", "west",
    });
}
