inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Delilah's Deli";
    long_desc = "Delilah's Deli.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room302", "north",
    });
}
