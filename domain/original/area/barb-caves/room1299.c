inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Nursery";
    long_desc = "Nursery.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room1297", "north",
    });
}
