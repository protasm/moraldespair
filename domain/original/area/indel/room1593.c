inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "East Martial Row";
    long_desc = "East Martial Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1594", "north",
        "domain/original/area/indel/room1592", "west",
    });
}
