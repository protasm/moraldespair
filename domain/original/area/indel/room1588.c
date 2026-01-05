inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Deep Sea Thunder";
    long_desc = "Deep Sea Thunder.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "east",
        "domain/original/area/indel/room1589", "west",
    });
}
