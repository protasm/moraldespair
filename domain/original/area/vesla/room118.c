inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "A shaded walk";
    long_desc = "A shaded walk";
    dest_dir = ({
        "domain/original/area/vesla/room227", "north",
        "domain/original/area/vesla/room221", "south",
        "domain/original/area/vesla/room119", "west",
        "domain/original/area/vesla/room117", "east",
    });
}
