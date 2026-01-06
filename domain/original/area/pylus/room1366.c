inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Captain's office";
    long_desc = "Captain's office.\n";
    dest_dir = ({
        "domain/original/area/pylus/room1365", "east",
    });
}
