inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pensji Lane";
    long_desc = "Pensji Lane.\n";
    dest_dir = ({
        "domain/original/area/indel/room1524", "north",
        "domain/original/area/indel/room1526", "south",
        "domain/original/area/indel/room1606", "east",
    });
}
