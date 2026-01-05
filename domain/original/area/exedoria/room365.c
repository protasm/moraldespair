inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A monk's cell";
    long_desc = "A monk's cell.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room364", "east",
    });
}
