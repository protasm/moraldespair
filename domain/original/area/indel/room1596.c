inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Parade Grounds";
    long_desc = "Parade Grounds.\n";
    dest_dir = ({
        "domain/original/area/indel/room1597", "north",
        "domain/original/area/indel/room1595", "east",
    });
}
