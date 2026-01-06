inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Entrance to Queen's Meadow";
    long_desc = "Entrance to Queen's Meadow.\n";
    dest_dir = ({
        "domain/original/area/preserve/room445", "south",
        "domain/original/area/preserve/room447", "north",
    });
}
