inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Church Road";
    long_desc = "West Church Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1559", "north",
        "domain/original/area/indel/room1544", "south",
    });
}
