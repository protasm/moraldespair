inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Ambassadors Suite";
    long_desc = "Ambassadors Suite.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room921", "south",
    });
}
