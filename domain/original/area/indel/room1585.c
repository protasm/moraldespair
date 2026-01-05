inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Castle Drawbridge";
    long_desc = "Castle Drawbridge.\n";
    dest_dir = ({
        "domain/original/area/indel/room1579", "north",
        "domain/original/area/indel/room1586", "south",
    });
}
