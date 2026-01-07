inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Shattered Northern Main Road";
    long_desc = "The northern main road is cracked and heaved, with chunks of masonry strewn across it. Heat-blistered stone and deep gouges linger like the passage of something vast. Grease-dark stains and splintered bones collect in sheltered corners.\n";
    dest_dir = ({
        "domain/original/area/vesla/room125", "south",
        "domain/original/area/vesla/room412", "east",
        "domain/original/area/vesla/room161", "north",
    });
}
