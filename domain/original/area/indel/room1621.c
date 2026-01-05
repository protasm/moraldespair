inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sithicus";
    long_desc = "Sithicus.\n";
    dest_dir = ({
        "domain/original/area/indel/room1514", "south",
    });
}
