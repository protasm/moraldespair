inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hay Loft";
    long_desc = "A collapsed loft hangs above, its beams broken and draped in cobwebs. Dry chaff dust coats the ground, now darkened by years of damp.";
    dest_dir = ({
        "domain/original/area/vesla/room783", "southwest",
        "domain/original/area/vesla/room777", "west",
        "domain/original/area/vesla/room780", "northwest",
        "domain/original/area/vesla/room779", "south",
    });
}

