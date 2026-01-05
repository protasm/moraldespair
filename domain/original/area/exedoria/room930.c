inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Machinery Room";
    long_desc = "Machinery Room.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room929", "down",
    });
}
