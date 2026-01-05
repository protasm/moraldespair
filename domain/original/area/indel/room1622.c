inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Mother Whitman's Confections Shop";
    long_desc = "Mother Whitman's Confections Shop.\n";
    dest_dir = ({
        "domain/original/area/indel/room1511", "south",
    });
}
