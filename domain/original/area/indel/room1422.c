inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Pier Street west of the Waterfront Gate";
    long_desc = "Pier Street west of the Waterfront Gate.\n";
    dest_dir = ({
        "domain/original/area/indel/room1421", "north",
        "domain/original/area/indel/room1423", "south",
    });
}
