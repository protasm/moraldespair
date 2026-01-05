inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Gravel path to the mansion";
    long_desc = "Gravel path to the mansion.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room379", "east",
        "domain/original/area/exedoria/room371", "west",
    });
}
