inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Elevated park path";
    long_desc = "Elevated park path.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room373", "south",
        "domain/original/area/exedoria/room375", "north",
    });
}
