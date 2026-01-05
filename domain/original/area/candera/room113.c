inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Temple of Fire";
    long_desc = "Temple of Fire.\n";
    dest_dir = ({
        "domain/original/area/candera/room112", "east",
        "domain/original/area/candera/room1129", "up",
    });
}
