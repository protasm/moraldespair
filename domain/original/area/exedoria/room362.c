inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cobblestoned hallway";
    long_desc = "Cobblestoned hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room356", "south",
        "domain/original/area/exedoria/room363", "east",
        "domain/original/area/exedoria/room364", "north",
    });
}
