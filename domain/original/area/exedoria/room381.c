inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Before a white mansion";
    long_desc = "Before a white mansion.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room380", "south",
    });
}
