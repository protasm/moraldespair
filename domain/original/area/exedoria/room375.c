inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "End of park path";
    long_desc = "End of park path.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room376", "east",
        "domain/original/area/exedoria/room374", "south",
    });
}
