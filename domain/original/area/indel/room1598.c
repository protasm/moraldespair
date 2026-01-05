inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Training Grounds";
    long_desc = "Training Grounds.\n";
    dest_dir = ({
        "domain/original/area/indel/room1599", "north",
        "domain/original/area/indel/room1597", "south",
        "domain/original/area/indel/room1600", "east",
    });
}
