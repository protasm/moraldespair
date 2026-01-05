inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "West Merchant's Row, south of Laird's Forge";
    long_desc = "West Merchant's Row, south of Laird's Forge.\n";
    dest_dir = ({
        "domain/original/area/indel/room1415", "east",
        "domain/original/area/indel/room1417", "west",
    });
}
