inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Overgrown Beds";
    long_desc = "Overgrown beds sag beneath nettles and mildew-dark leaves, their borders crumbled. A fallen trellis and a cracked basin suggest careful tending long since undone.";
    dest_dir = ({
        "domain/original/area/vesla/room168", "east",
    });
}

