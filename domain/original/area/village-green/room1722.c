inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "The Herb Exchange";
    long_desc = "The Herb Exchange.\n";
    dest_dir = ({
        "domain/original/area/village-green/room1710", "west",
    });
}
