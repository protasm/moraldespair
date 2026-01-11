inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Scholar's Way";
    long_desc = "Scholar's Way\n";
    dest_dir = ({
        "domain/original/area/vesla/room742", "south",
        "domain/original/area/vesla/room192", "west",
        "domain/original/area/vesla/room190", "east",
        "domain/original/area/vesla/room743", "north",
    });
}
