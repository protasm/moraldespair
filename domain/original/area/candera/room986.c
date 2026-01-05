inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Sleeping Quarters";
    long_desc = "Sleeping Quarters.\n";
    dest_dir = ({
        "domain/original/area/candera/room973", "south",
    });
}
