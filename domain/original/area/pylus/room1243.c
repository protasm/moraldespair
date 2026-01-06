inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Vegetable seller's";
    long_desc = "Vegetable seller's.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1228", "west",
    });
}
