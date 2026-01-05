inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gravel Path";
    long_desc = "Gravel Path.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room908", "northwest",
        "domain/original/area/exedoria/room604", "southwest",
    });
}
