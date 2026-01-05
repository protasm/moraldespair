inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "New Outer Wall";
    long_desc = "New Outer Wall.\n";
    dest_dir = ({
        "domain/original/area/candera/room3", "east",
        "domain/original/area/candera/room1", "west",
    });
}
