inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Science building's entry";
    long_desc = "Science building's entry.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room905", "west",
        "domain/original/area/exedoria/room906", "east",
        "domain/original/area/exedoria/room390", "north",
    });
}
