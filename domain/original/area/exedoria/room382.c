inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Outside the cemetery gate";
    long_desc = "Outside the cemetery gate.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room380", "northwest",
    });
}
