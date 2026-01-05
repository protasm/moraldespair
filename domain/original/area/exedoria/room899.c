inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Southern path through the University";
    long_desc = "Southern path through the University.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room902", "south",
        "domain/original/area/exedoria/room900", "east",
        "domain/original/area/exedoria/room898", "north",
    });
}
