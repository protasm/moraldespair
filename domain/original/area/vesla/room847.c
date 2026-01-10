inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Old City Offices";
    long_desc = "Old City Offices\n";
    dest_dir = ({
        "domain/original/area/vesla/room849", "west",
        "domain/original/area/vesla/room848", "east",
        "domain/original/area/vesla/room144", "north",
    });
}
