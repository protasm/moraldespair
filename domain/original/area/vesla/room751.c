inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Hushed Cots";
    long_desc = "Low bed frames run along the sides, stripped to bare ribs and powdery\n"
                + "with dust. The ceiling sags, and the stale air holds the hint of old\n"
                + "bedding.\n";
    dest_dir = ({
        "domain/original/area/vesla/room748", "east",
    });
}

