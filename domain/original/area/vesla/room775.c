inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Silted Run";
    long_desc = "A narrow run between stalls is choked with silt and crumbled wood. The rails are split, and the stone base is slick with moss.";
    dest_dir = ({
        "domain/original/area/vesla/room784", "south",
        "domain/original/area/vesla/room774", "west",
        "domain/original/area/vesla/room776", "east",
        "domain/original/area/vesla/room785", "north",
    });
}

