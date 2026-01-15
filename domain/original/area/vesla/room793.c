inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Overgrown Beds";
    long_desc = "Overgrown beds sag beneath nettles and mildew-dark leaves, their borders\n"
                + "crumbled. A fallen trellis and a cracked basin suggest careful tending\n"
                + "long since undone.\n";
    dest_dir = ({
        "domain/original/area/vesla/room168", "east",
    });
}

