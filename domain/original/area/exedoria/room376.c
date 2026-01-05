inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple ruins";
    long_desc = "Temple ruins.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room377", "east",
        "domain/original/area/exedoria/room375", "west",
    });
}
