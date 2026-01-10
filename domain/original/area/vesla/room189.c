inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way";
    dest_dir = ({
        "domain/original/area/vesla/room190", "west",
        "domain/original/area/vesla/room188", "east",
        "domain/original/area/vesla/room739", "south",
    });
}

