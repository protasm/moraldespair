inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered North Main Street";
    long_desc = "North Main is cracked and heaved, with chunks of masonry strewn across it. Heat-blistered stone and deep gouges linger like the passage of something vast. Grease-dark stains and splintered bones collect in sheltered corners.\n";
    dest_dir = ({
        "domain/original/area/vesla/room164", "south",
        "domain/original/area/vesla/room166", "north",
    });
}
