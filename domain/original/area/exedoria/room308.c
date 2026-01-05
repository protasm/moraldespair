inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Beginning of Lilu Lane";
    long_desc = "Beginning of Lilu Lane.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room309", "south",
        "domain/original/area/exedoria/room307", "north",
    });
}
