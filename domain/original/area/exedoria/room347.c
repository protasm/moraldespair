inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Icy room";
    long_desc = "Icy room.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room346", "west",
    });
}
