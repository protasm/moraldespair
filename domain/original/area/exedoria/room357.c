inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Cobblestoned hallway";
    long_desc = "Cobblestoned hallway.\n";
    dest_dir = ({
        "domain/original/area/exedoria/room358", "south",
        "domain/original/area/exedoria/room360", "east",
        "domain/original/area/exedoria/room356", "north",
    });
}
