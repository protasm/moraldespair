inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Northern End of Via Sacra";
    long_desc = "Northern End of Via Sacra.\n";
    dest_dir = ({
        "domain/original/area/vesla/room219", "south",
        "domain/original/area/vesla/room221", "west",
        "domain/original/area/vesla/room233", "east",
        "domain/original/area/vesla/room117", "north",
    });
}
