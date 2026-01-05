inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Banana Hammock";
    long_desc = "The Banana Hammock.\n";
    dest_dir = ({
        "domain/original/area/anshelm/room1191", "west",
        "domain/original/area/anshelm/room1186", "south",
    });
}
