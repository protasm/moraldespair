inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Intersection of Martial Row and Pensji Lane";
    long_desc = "Intersection of Martial Row and Pensji Lane.\n";
    dest_dir = ({
        "domain/original/area/indel/room1534", "north",
        "domain/original/area/indel/room1591", "east",
        "domain/original/area/indel/room1541", "west",
    });
}
