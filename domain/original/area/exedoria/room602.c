inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Railed entrance";
    long_desc = "Railed entrance.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room336", "south",
    });
}
