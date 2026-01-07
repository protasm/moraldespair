inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Corridor";
    long_desc = "Corridor.\n";
    dest_dir = ({
        "domain/original/area/barb-caves/room519", "east",
        "domain/original/area/barb-caves/room516", "west",
    });
}
