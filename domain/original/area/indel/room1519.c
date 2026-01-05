inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of Merchant's Row";
    long_desc = "End of Merchant's Row.\n";
    dest_dir = ({
        "domain/original/area/indel/room1518", "west",
    });
}
