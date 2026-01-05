inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Livestock Lot";
    long_desc = "Livestock Lot.\n";
    dest_dir = ({
        "domain/original/area/indel/room1643", "north",
        "domain/original/area/indel/room1510", "south",
    });
}
