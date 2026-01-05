inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "City Hall";
    long_desc = "City Hall.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room291", "north",
    });
}
