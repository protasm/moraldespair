inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Ready Room";
    long_desc = "West Ready Room.\n";
    dest_dir = ({
        "domain/original/area/indel/room1401", "east",
    });
}
