inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Muddy Lane";
    long_desc = "Muddy Lane.\n";
    dest_dir = ({
        "domain/original/area/indel/room1634", "east",
        "domain/original/area/indel/room1402", "west",
    });
}
