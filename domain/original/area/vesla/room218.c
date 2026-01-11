inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Cracked Way";
    long_desc = "Loose stones crunch under a thin coat of dust. A rusted bracket clings to the\n"
                + "wall, its mate long gone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room217", "south",
        "domain/original/area/vesla/room219", "north",
    });
}
