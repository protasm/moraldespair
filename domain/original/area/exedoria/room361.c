inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "With a grunt of effort, you manage to push open the heavy door, and enter";
    long_desc = "With a grunt of effort, you manage to push open the heavy door, and enter.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room356", "east",
    });
}
