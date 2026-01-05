inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Castle Road and Church Road";
    long_desc = "Intersection of Castle Road and Church Road.\n";
    dest_dir = ({
        "domain/original/area/indel/room1584", "north",
        "domain/original/area/indel/room1585", "south",
        "domain/original/area/indel/room1580", "east",
        "domain/original/area/indel/room1578", "west",
    });
}
