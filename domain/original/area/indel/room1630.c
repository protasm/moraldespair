inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Burrow's Map Shop";
    long_desc = "Burrow's Map Shop.\n";
    dest_dir = ({
        "domain/original/area/indel/room1403", "west",
    });
}
