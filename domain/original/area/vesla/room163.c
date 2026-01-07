inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered North Main Street";
    long_desc = "North Main is cracked and heaved, with chunks of masonry strewn across it. Heat-blistered stone and deep gouges linger like the passage of something vast. Grease-dark stains and splintered bones collect in sheltered corners.\n";
    dest_dir = ({
        "domain/original/area/vesla/room162", "south",
        "domain/original/area/vesla/room811", "east",
        "domain/original/area/vesla/room164", "north",
    });
}

void init() {
    add_action("block_structure", "east");
}

int block_structure() {
    write("Only rubble remains there; the structure collapsed long ago.\n");
    return 1;
}
