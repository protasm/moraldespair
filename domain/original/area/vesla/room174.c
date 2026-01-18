inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Rutted Road";
    long_desc = "A stretch of broken cobbles continues through the husks of old shops, their beams exposed to sky. Weeds knot in the joints where carts once passed.";
    dest_dir = ({
        "domain/original/area/vesla/room173", "south",
        "domain/original/area/vesla/room175", "north",
    });
}
