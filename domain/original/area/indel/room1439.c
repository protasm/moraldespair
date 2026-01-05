inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Forester's Gate";
    long_desc = "Forester's Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1438", "north",
    });
}
