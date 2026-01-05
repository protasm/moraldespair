inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stockade";
    long_desc = "Stockade.\n";
    dest_dir = ({
        "domain/original/area/indel/room1600", "west",
    });
}
