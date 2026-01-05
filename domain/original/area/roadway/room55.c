inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Near Indel City";
    long_desc = "Near Indel City.\n";
    dest_dir = ({
        "domain/original/area/roadway/room54", "north",
        "domain/original/area/indel/room1401", "city",
    });
}
