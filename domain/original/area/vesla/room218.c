inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);
    short_desc = "Sacra Way";
    long_desc = "Loose stones crunch under a thin coat of dust.\n"
                + "A rusted bracket clings to the wall, its mate long gone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room217", "south",
        "domain/original/area/vesla/room219", "north",
    });
}
