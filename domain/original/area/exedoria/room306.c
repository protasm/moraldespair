inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Brapnor Road";
    long_desc = "Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room305", "east",
        "domain/original/area/exedoria/room307", "west",
    });
}
