inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Trinian merchant's office";
    long_desc = "Trinian merchant's office.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room916", "north",
    });
}
