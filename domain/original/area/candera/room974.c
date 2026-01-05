inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Living Quarters";
    long_desc = "Living Quarters.\n";
    dest_dir = ({
        "domain/original/area/candera/room973", "north",
    });
}
