inherit "room/room";

void reset(int arg) {
    if (arg)
        return;

    set_light(1);

    short_desc = "Stone Passage";
    long_desc = "The wall looms close over a cramped passage of worn stone, the gaps filled with dust. Rusty brackets jut from the masonry, and the air carries the chill of old damp.";
    dest_dir = ({
        "chapter/prologue/area/ruined/room183", "east",
    });
}

