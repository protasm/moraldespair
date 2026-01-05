inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Lilu Lane";
    long_desc = "Lilu Lane.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room312", "south",
        "domain/original/area/exedoria/room310", "north",
    });
}
