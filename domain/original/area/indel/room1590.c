inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Horrors of the Deep";
    long_desc = "Horrors of the Deep.\n";
    dest_dir = ({
        "domain/original/area/indel/room1409", "north",
        "domain/original/area/indel/room1589", "east",
    });
}
