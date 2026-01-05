inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "With a little strain, you are able to pull open the heavy doors and enter";
    long_desc = "With a little strain, you are able to pull open the heavy doors and enter.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1330", "east",
        "domain/original/area/anshelm/room1328", "west",
    });
}
