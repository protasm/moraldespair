inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Westroad";
    long_desc = "Westroad\n";
    dest_dir = ({
        "domain/original/area/vesla/room131", "west",
        "domain/original/area/vesla/room129", "east",
        "domain/original/area/vesla/room420", "south",
    });
}

