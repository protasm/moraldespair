inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Westroad";
    long_desc = "Westroad";
    dest_dir = ({
        "domain/original/area/vesla/room130", "west",
        "domain/original/area/vesla/room128", "east",
        "domain/original/area/vesla/room419", "south",
    });
}

