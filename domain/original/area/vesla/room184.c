inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stone Passage";
    long_desc = "The wall looms close over a cramped passage of worn stone, the gaps\n"
                + "filled with dust. Rusty brackets jut from the masonry, and the air\n"
                + "carries the chill of old damp.\n";
    dest_dir = ({
        "domain/original/area/vesla/room183", "east",
    });
}

