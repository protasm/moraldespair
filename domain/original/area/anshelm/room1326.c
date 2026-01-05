inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "La Cosa Nostra";
    long_desc = "La Cosa Nostra.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room283", "south",
    });
}
