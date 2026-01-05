inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cold hallway";
    long_desc = "Cold hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room346", "east",
        "domain/original/area/exedoria/room349", "south",
    });
}
