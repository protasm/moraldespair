inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row";
    long_desc = "West Merchant's Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1411", "east",
        "domain/original/area/indel/room1413", "west",
    });
}
