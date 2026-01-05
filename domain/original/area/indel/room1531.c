inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pensji Lane";
    long_desc = "Pensji Lane.\n";
    dest_dir = ({
        "domain/original/area/indel/room1530", "north",
        "domain/original/area/indel/room1532", "south",
    });
}
