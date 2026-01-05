inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before a round door";
    long_desc = "Before a round door.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room315", "north",
    });
}
