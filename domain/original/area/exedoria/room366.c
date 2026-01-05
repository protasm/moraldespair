inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Cadaver Emporium";
    long_desc = "The Cadaver Emporium.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room289", "north",
    });
}
