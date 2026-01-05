inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The end of the park street";
    long_desc = "The end of the park street.\n";
    dest_dir = ({
        "domain/original/area/vesla/room880", "south",
        "domain/original/area/vesla/room127", "west",
        "domain/original/area/vesla/room125", "east",
        "domain/original/area/vesla/room879", "north",
    });
}
