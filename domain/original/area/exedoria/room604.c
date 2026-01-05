inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "You rudely trespass on the private property.";
    long_desc = "You rudely trespass on the private property.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room907", "northeast",
        "domain/original/area/exedoria/room910", "northwest",
        "domain/original/area/exedoria/room338", "south",
    });
}
