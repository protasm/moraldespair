inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Middle of Brapnor Road";
    long_desc = "Middle of Brapnor Road.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room304", "west",
        "domain/original/area/exedoria/room302", "east",
        "domain/original/area/exedoria/room329", "south",
    });
}
