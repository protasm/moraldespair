inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Jack's Bistro";
    long_desc = "Jack's Bistro.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1190", "east",
        "domain/original/area/anshelm/room1185", "south",
    });
}
