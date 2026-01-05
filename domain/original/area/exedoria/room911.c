inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Child's Den";
    long_desc = "Child's Den.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room909", "east",
    });
}
