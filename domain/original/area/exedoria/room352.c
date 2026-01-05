inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Wood-paneled Hallway";
    long_desc = "Wood-paneled Hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room351", "west",
        "domain/original/area/exedoria/room353", "north",
    });
}
