inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Store Room";
    long_desc = "Store Room.\n";
    dest_dir = ({
        "domain/original/area/vesla/room745", "west",
    });
}
