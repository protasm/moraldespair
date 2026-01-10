inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Small paddock";
    long_desc = "Small paddock\n";
    dest_dir = ({
        "domain/original/area/vesla/room783", "southwest",
        "domain/original/area/vesla/room777", "west",
        "domain/original/area/vesla/room780", "northwest",
        "domain/original/area/vesla/room779", "south",
    });
}
