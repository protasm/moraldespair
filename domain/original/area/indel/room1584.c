inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Olde City Gate";
    long_desc = "Olde City Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1406", "north",
        "domain/original/area/indel/room1579", "south",
        "domain/original/area/indel/room1587", "east",
        "domain/original/area/indel/room1588", "west",
    });
}
