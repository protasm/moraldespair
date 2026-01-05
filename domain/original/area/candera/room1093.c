inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Goondala's Flowers";
    long_desc = "Goondala's Flowers.\n";
    dest_dir = ({
        "domain/original/area/candera/room90", "east",
    });
}
