inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered North Main Street";
    long_desc = "North Main is cracked and heaved, with chunks of masonry strewn across it. Long ago the dragons laid it waste, and it has never recovered.\n";
    dest_dir = ({
        "domain/original/area/vesla/room163", "south",
        "domain/original/area/vesla/room812", "east",
        "domain/original/area/vesla/room165", "north",
    });
}

void init() {
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
