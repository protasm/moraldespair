inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hay Loft";
    long_desc = "A collapsed loft hangs above, its beams broken and draped in cobwebs.\n"
                + "Dry chaff dust coats the ground, now darkened by years of damp.\n";
    dest_dir = ({
        "domain/original/area/vesla/room783", "southwest",
        "domain/original/area/vesla/room777", "west",
        "domain/original/area/vesla/room780", "northwest",
        "domain/original/area/vesla/room779", "south",
    });
}

