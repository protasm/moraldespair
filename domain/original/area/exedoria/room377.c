inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple rotunda";
    long_desc = "Temple rotunda.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room376", "west",
    });
}
