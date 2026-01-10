inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Dusty Ruins";
    long_desc = "Dusty Ruins";
    dest_dir = ({
        "domain/original/area/vesla/room745", "west",
    });
}
