inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "North Main Road";
    long_desc = "The north road levels out and grows quiet, its surface\n"
                + "scabbed with grit.\n"
                + "A cracked iron grate lies in the gutter.\n";
    dest_dir = ({
        "domain/original/area/vesla/room164", "south",
        "domain/original/area/vesla/room166", "north",
    });
}
