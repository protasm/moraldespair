inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Big Hole Banking";
    long_desc = "Big Hole Banking";
    dest_dir = ({
        "domain/original/area/vesla/room225", "west",
        "domain/original/area/vesla/room223", "east",
        "domain/original/area/vesla/room121", "north",
    });
}
